#include "sdb.h"

sdbstate state = NOTLOAD;
unsigned long long last_addr = 0;

struct pInfo_t *pinfo;
/*****************************************
 *
 *             start
 *
 * ***************************************/
void init_bp_to_start(struct pInfo_t *pinfo)
{
    struct breakpointList_t *cur = pinfo->bplist;

    while (cur)
    {
        LOGD("[LOGGER] init bp to start: %llx\n", cur->address);
        long code = bp_set(cur->address, pinfo);
        cur->code = code;
        cur = cur->next;
    }
}
void init_regs(struct user_regs_struct **regs)
{
    (*regs) = (struct user_regs_struct *)malloc(sizeof(struct user_regs_struct));
}
void init_start_pinfo(struct pInfo_t *pinfo)
{
    pinfo->terminiated = false;
    init_regs(&pinfo->regs);
    init_bp_to_start(pinfo);
}
/*****************************************
 *
 *             disasm
 *
 * ***************************************/
int disasm_init(struct disasm_t **self, unsigned char *code, int size, long addrNum)
{
    csh handle;

    if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK)
        return CSH_FAIL;

    cs_insn *insn;
    size_t count;

    (*self) = (struct disasm_t *)malloc(sizeof(struct disasm_t));
    count = cs_disasm(handle, code, size, addrNum, 0, &insn);
    LOGD("[LOGGER] cs_disasm ret:%lu\n", count);
    if (count <= 0)
        return DISASM_FAIL;
    (*self)->instrId = 0;
    (*self)->instrSize = count;
    (*self)->insn = insn;

    return DISASM_SUCC;
}
int disasm_textInit(struct pInfo_t *pinfo, long addr)
{
    int status;
    long offset = addr - pinfo->elf->entry;
    long size = pinfo->elf->text_size - offset;
    if (offset < 0 || size < 0)
    {
        printf("** addr not available\n");
        return 0;
    }
    status = disasm_init(&(pinfo->disasm), pinfo->elf->text_section + offset, size, addr);
    if (status == DISASM_SUCC)
    {
        LOGD("[LOGGER] disasm successfully\n");
        return 1;
    }
    if (status == CSH_FAIL)
        LOGD("[ERROR] csh handler fail\n");

    if (status == DISASM_FAIL)
        LOGD("[ERROR] disasm fail\n");

    return 0;
}
void disasm_show(struct disasm_t *self)
{
    if (self->instrId < self->instrSize)
    {
        int printLine = 10;
        while (printLine && self->instrId < self->instrSize)
        {
            printf("\t%06lx: ", self->insn[self->instrId].address);

            int spaceSize = 20;
            for (int i = 0; i < self->insn[self->instrId].size; i++)
            {
                printf("%02x ", self->insn[self->instrId].bytes[i]);
                spaceSize -= 3;
            }
            for (int i = 0; i < spaceSize; i++)
                printf(" ");

            printf("\t\t%s\t%s\n",
                   self->insn[self->instrId].mnemonic, self->insn[self->instrId].op_str);

            printLine--;
            self->instrId++;
        }
    }
    else
    {
        cs_free(self->insn, self->instrSize);
        printf("** no addr is given.\n");
    }
}
int disasm_word(unsigned char *code, long addrNum, char **buffer)
{
    csh handle;

    if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK)
        return -1;

    cs_insn *insn;
    size_t count;

    count = cs_disasm(handle, code, sizeof(long), addrNum, 1, &insn);
    sprintf(*buffer, "0x%06lx: ", insn[0].address);
    char bytecode[64] = {'\0'};
    int spaceSize = 20;
    for (int i = 0; i < insn[0].size; i++)
    {
        sprintf(*buffer, "%s%02x ", *buffer, insn[0].bytes[i]);
        spaceSize -= 3;
    }
    for (int i = 0; i < spaceSize; i++)
        sprintf(*buffer, "%s ", *buffer);
    sprintf(*buffer, "%s\t%s\t%s", *buffer, insn[0].mnemonic, insn[0].op_str);

    return insn[0].size;
}
long disasm_runtime(long addrNum, pid_t pid)
{
    long ret;
    unsigned char *byteCode = (unsigned char *)&ret;

    char *buffer = (char *)malloc(sizeof(char) * 128);
    int offset = 0;

    // only have to dump 10 instructions
    for (int i = 0; i < 10; i++)
    {
        addrNum += offset;
        ret = ptrace(PTRACE_PEEKTEXT, pid, addrNum, 0);

        memset(buffer, '\0', 128);
        offset = disasm_word(byteCode, addrNum, &buffer);
        if (offset == 0)
            break;
        printf("\t%s\n", buffer);
    }
    free(buffer);

    return addrNum;
}
/*****************************************
 *
 *             register
 *
 * ***************************************/
bool read_reg(struct user_regs_struct *regs, pid_t pid)
{
    // try to read procces regs
    LOGD("[LOGGER] pid: %d\n", pid);
    if (pid <= 0)
    {
        LOGD("[ERROR] read_reg and process not running\n");
        printf("** program isn't running, please call break after start.\n");
        return false;
    }

    if (ptrace(PTRACE_GETREGS, pid, 0, regs) < 0)
    {
        LOGD("[ERROR] get register fail\n");
        return false;
    }

    return true;
}
void set_reg(struct user_regs_struct *regs, string targetReg, long regVal, pid_t pid)
{
    LOGD("[LOGGER] targetReg:%s regVal:%lu\n", targetReg.c_str(), regVal);
    SET_REG(rax);
    SET_REG(rbx);
    SET_REG(rcx);
    SET_REG(rdx);
    SET_REG(r8);
    SET_REG(r9);
    SET_REG(r10);
    SET_REG(r11);
    SET_REG(r12);
    SET_REG(r13);
    SET_REG(r14);
    SET_REG(r15);
    SET_REG(rdi);
    SET_REG(rsi);
    SET_REG(rbp);
    SET_REG(rsp);
    SET_REG(rip);
    if (targetReg == "flags")
    {
        regs->eflags = regVal;
        if (ptrace(PTRACE_SETREGS, pid, 0, regs) == 0)
            return;
        else
            LOGD("[ERROR] set register fail\n");
        return;
    }
    printf("** %s is not allowed\n", targetReg.c_str());
}

/*****************************************
 *
 *             dump
 *
 * ***************************************/
void dump_init(struct dump_t **self, unsigned long long addr)
{
    (*self) = (struct dump_t *)malloc(sizeof(struct dump_t));
    (*self)->dumpAddr = addr;
}
void dump_show(struct dump_t *self, pid_t pid)
{
    long ret;
    unsigned char *byteCode = (unsigned char *)&ret;
    int addrSize = sizeof(unsigned long long);
    unsigned char twoWordCode[16];

    for (int j = 0; j < 5; j++)
    {
        printf("%05llx:  ", self->dumpAddr);
        ret = ptrace(PTRACE_PEEKTEXT, pid, self->dumpAddr, 0);
        for (int i = 0; i < addrSize; i++)
            twoWordCode[i] = byteCode[i];
        self->dumpAddr += 8;
        ret = ptrace(PTRACE_PEEKTEXT, pid, self->dumpAddr, 0);
        for (int i = 0; i < addrSize; i++)
            twoWordCode[i + 8] = byteCode[i];
        self->dumpAddr += 8;

        // print byte code
        for (int i = 0; i < addrSize * 2; i++)
            printf("%02x ", twoWordCode[i]);
        printf(" ");

        // print byte code in char
        printf("|");
        for (int i = 0; i < addrSize * 2; i++)
        {
            unsigned int thisNum = (unsigned int)twoWordCode[i];
            if (thisNum >= 32 && thisNum < 127)
                printf("%c", twoWordCode[i]);
            else
                printf(".");
        }
        printf("|");
        printf("\n");
    }
}

/*****************************************
 *
 *             break point
 *
 * ***************************************/
bool bp_recover(struct breakpointList_t **self, int id, pid_t pid)
{
    if (*self == NULL)
    {
        printf("** no breakpoint\n");
        return false;
    }

    struct breakpointList_t *cur = *self;
    struct breakpointList_t *prev = cur;
    int order = 0;
    while (cur)
    {
        if (order == id)
        {
            if (*self == cur && !(cur->next))
                *self = NULL;
            if (*self == cur && cur->next)
                *self = cur->next;
            if (*self != cur)
                prev->next = cur->next;
            break;
        }
        prev = cur;
        cur = cur->next;
        order++;
    }
    if (order != id)
    {
        printf("** breakpoint id not allowed\n");
        return false;
    }
    // PRINTLINE;
    if (id <= 0)
        return true;
    if (ptrace(PTRACE_POKETEXT, pid, cur->address, cur->code) != 0)
        LOGD("[ERROR] restore bp fail\n");
    free(cur);
    // PRINTLINE;
    return true;
}
long bp_set(unsigned long long addrPos, struct pInfo_t *pinfo)
{

    /* get original text */
    long code = ptrace(PTRACE_PEEKTEXT, pinfo->pid, addrPos, 0);
    // perror("[ERROR] ptrace");

    LOGD("[LOGGER] bp_set: addr:%llx, code: %lx pid:%d\n", addrPos, code, pinfo->pid);

    /* set break point */
    if (ptrace(PTRACE_POKETEXT, pinfo->pid, addrPos, (code & 0xffffffffffffff00) | (0xcc & 0xff)) != 0)
        LOGD("[ERROR] set breakpoint fail\n");
    else
        LOGD("[LOGGER] change byte code 0xcc succ\n");
    return code;
}
long bp_get_code(struct breakpointList_t **self, unsigned long long stopaddr)
{
    struct breakpointList_t *cur = *self;

    while (cur)
    {
        if (cur->address == stopaddr)
        {
            return cur->code;
        }
        cur = cur->next;
    }
    return -1;
}
bool bp_isinlist(struct breakpointList_t **self, unsigned long long rip)
{
    // just check bp is in list
    struct breakpointList_t *cur = *self;
    while (cur)
    {
        if (cur->address == rip)
            return true;

        cur = cur->next;
    }
    return false;
}
void bp_store(struct breakpointList_t **self, unsigned long long address, long code)
{
    struct breakpointList_t *temp;
    temp = (struct breakpointList_t *)malloc(sizeof(struct breakpointList_t));

    temp->address = address;
    temp->code = code;
    temp->next = NULL;

    if (*self == NULL)
    {
        (*self) = temp;
        LOGD("[LOGGER] fist breakpoint (%p)\n", (*self));
        return;
    }
    struct breakpointList_t *cur = *self;
    while (cur->next)
        cur = cur->next;
    cur->next = temp;
}

/*****************************************
 *
 *             sdb cmd
 *
 * ***************************************/
void breakpt(string addr)
{
    unsigned long long addrPos = stoull(addr, NULL, 16); // b 0x4000c6

    if (state != RUNNING)
    {
        printf("** program isn't running, please call break after start.\n");
        return;
    }
    long orig_code;

    orig_code = ptrace(PTRACE_PEEKTEXT, pinfo->pid, addrPos, 0);
    if (ptrace(PTRACE_POKETEXT, pinfo->pid, addrPos, (orig_code & 0xffffffffffffff00) | (0xcc & 0xff)) != 0)
        LOGD("[ERROR] set breakpoint fail\n");
    else
        LOGD("[LOGGER] change byte code 0xcc succ\n");
    bp_store(&pinfo->bplist, addrPos, orig_code);
}
void cont()
{
    if (state != RUNNING)
    {
        printf("** program is not running\n");
        return;
    }
    int status;
    if (!read_reg(pinfo->regs, pinfo->pid))
        LOGD("read_reg fail\n");

    unsigned long long rip = (pinfo->regs)->rip;
    if (bp_isinlist(&pinfo->bplist, last_addr))
    {
        LOGD("[LOGGER]stop at bp, so patch 0xcc again then cont\n");
        si();
        bp_set(last_addr, pinfo);
    }
    ptrace(PTRACE_CONT, pinfo->pid, 0, 0);
    waitpid(pinfo->pid, &status, 0);

    if (WIFSTOPPED(status) && !(WSTOPSIG(status) & 0x80))
    {
        // if( WIFSTOPPED(status) ){
        LOGD(" [LOGGER]process stop\n");
        if (read_reg(pinfo->regs, pinfo->pid))
        {
            // unsigned long long stopaddr = pinfo->regs->rip - 1;
            last_addr = pinfo->regs->rip - 1;
            long code;

            // LOGD("stop addr: %llx\n", stopaddr);
            // get the stopaddr(==breakpoint) 's origin code
            code = bp_get_code(&pinfo->bplist, last_addr);

            LOGD("[LOGGER] get bp <%llx> 's (orig code): %lx\n", last_addr, code);
            if (code)
            {
                LOGD("[LOGGER] is break point\n");

                // restore rip (pc)
                set_reg(pinfo->regs, "rip", pinfo->regs->rip - 1, pinfo->pid);
                LOGD("[LOGGER] reset rip %llx\n", pinfo->regs->rip);

                // restore to orig_code
                if (ptrace(PTRACE_POKETEXT, pinfo->pid, last_addr, code) != 0)
                    LOGD("[ERROR] restore bp fail\n");
                LOGD("[LOGGER] restore code %lx\n", code);

                // disasm program bytecode
                char *buffer = (char *)malloc(sizeof(char) * 128);
                disasm_word((unsigned char *)&code, last_addr, &buffer);
                printf("** breakpoint @ \t%s\n", buffer);
                free(buffer);

                // to reuse the bp, run si first then put 0xcc back
                // but must to check the bp is still in bplist
                // si();
                // bp_set( stopaddr, pinfo );
            }
        }
    }
    if (WIFEXITED(status))
    {
        pinfo->terminiated = true;
        state = LOADED;
        printf("** child process %d terminiated normally code(%d)\n", pinfo->pid, status);
    }
}
void bp_delete(int id)
{
    if (state != RUNNING)
    {
        printf("** program isn't running, please call break after start.\n");
        return;
    }
    LOGD("[LOGGER] delete breakpoint %d\n", id);
    if (bp_recover(&pinfo->bplist, id, pinfo->pid))
        printf("** breakpoint %d deleted.\n", id);
    else
        printf("** breakpoint %d deleted failed.\n", id);
}
void disasm(vector<string> line)
{
    // cmd: disasm [addr]

    if (state != RUNNING)
    {
        printf("** program isn't running, please call break after start.\n");
        return;
    }
    // if disasm command is executed without an address, you can simply output ** no addr is given.
    if (line.size() == 1)
    {
        printf("** no addr is given.\n");
        return;
    }

    long addrNum = stol(line[1], NULL, 16);
    if (disasm_textInit(pinfo, addrNum))
        disasm_show(pinfo->disasm);
}
void dump(vector<string> line)
{
    //  If dump command is executed without an address,
    //  it should dump the region right after the previous dump.

    if (state != RUNNING)
    {
        printf("** program not start up\n");
        return;
    }
    // dump 如果沒給 address 統一輸出 "** no addr given.
    if (line.size() == 1)
    { // not input address
        printf("** no addr given.\n");
        return;
    }

    unsigned long long addr = stoull(line[1], nullptr, 16);
    dump_init(&(pinfo->dumpinfo), addr);
    dump_show(pinfo->dumpinfo, pinfo->pid);
}
void get(vector<string> line)
{
    if (state != RUNNING)
    {
        printf("** program isn't running, please call break after start.\n");
        return;
    }

    if (line.size() == 1)
    {
        printf("** usage: sdb> get <register name>\n");
        return;
    }
    string targetReg = line[1];

    if (read_reg(pinfo->regs, pinfo->pid))
    {
        struct user_regs_struct *regs = pinfo->regs;
        CHK_REG(rax);
        CHK_REG(rbx);
        CHK_REG(rcx);
        CHK_REG(rdx);
        CHK_REG(r8);
        CHK_REG(r9);
        CHK_REG(r10);
        CHK_REG(r11);
        CHK_REG(r12);
        CHK_REG(r13);
        CHK_REG(r14);
        CHK_REG(r15);
        CHK_REG(rdi);
        CHK_REG(rsi);
        CHK_REG(rbp);
        CHK_REG(rsp);
        CHK_REG(rip);
        if (targetReg == "flags")
        {
            printf("%s = %lld (0x%llx)\n", "flags", regs->eflags, regs->eflags);
            return;
        }
        printf("** %s is not allowed\n", targetReg.c_str());
    }

} // get
void getregs()
{
    if (state != RUNNING)
    {
        printf("** program isn't running, please call break after start.\n");
        return;
    }
    if (read_reg(pinfo->regs, pinfo->pid))
    {
        struct user_regs_struct *regs = pinfo->regs;
        printf("RAX %-18llxRBX %-18llxRCX %-18llx RDX %-18llx\n",
               regs->rax, regs->rbx, regs->rcx, regs->rdx);
        printf("R8  %-18llxR9  %-18llxR10 %-18llx R11 %-18llx\n",
               regs->r8, regs->r9, regs->r10, regs->r11);
        printf("R12 %-18llxR13 %-18llxR14 %-18llx R15 %-18llx\n",
               regs->r12, regs->r13, regs->r14, regs->r15);
        printf("RDI %-18llxRSI %-18llxRBP %-18llx RSP %-18llx\n",
               regs->rdi, regs->rsi, regs->rbp, regs->rsp);
        printf("RIP %-18llxFLAGS %016llx\n",
               regs->rip, regs->eflags);
    }
}
void help()
{
    printf(HELPMSG);
}
void list(struct breakpointList_t **self)
{
    LOGD("[LOGGER] bplist: %p\n", (*self));

    struct breakpointList_t *cur = *self;
    int order = 0;

    while (cur)
    {
        printf("  %d:   %06llx\n", order, cur->address);
        LOGD("[LOGGER] code: %lx\n", cur->code);
        cur = cur->next;
        order++;
    }
}
void load(vector<string> cmd)
{
    /*check prgrom load state
    cmd[0] is load(cmd)
    cmd[1] is program's name
    cmd[2] ... is program's argv*/

    if (state != NOTLOAD)
    {
        cerr << "** state must be NOTLOADED." << endl;
        return;
    }

    // init the process's info
    memset(pinfo, '\0', sizeof(struct pInfo_t));
    // PRINTLINE;
    //  handle program's path
    string progpath = cmd[1];
    if (progpath[0] != '.')
        strcpy(pinfo->name, progpath.c_str());

    int i = 0;
    for (; i + 2 < cmd.size(); i++)
        strcpy(pinfo->argv[i], cmd[i + 2].c_str());
    // pinfo->argv[i] = '\0';
    memset((pinfo->argv)[i], '\0', sizeof((pinfo->argv)[i]));
    for (int j = 0; j < sizeof((pinfo->argv)[i]); j++)
        (pinfo->argv)[i][j] = '\0';

    // handle program elf
    int status;
    if ((status = elf_check(pinfo->name)) == OPEN_SUCC)
    {
        // printf("[LOGGER] elf open succ\n");
        elf_init(&(pinfo->elf), pinfo->name);
        show_elf_info(pinfo->elf);
    }

    state = LOADED;
}
void run()
{
    if (state != RUNNING)
    {
        start();
        cont();
        return;
    }

    if (pinfo->terminiated)
        start();
    else
        printf("** program %s is already running.\n", pinfo->name);

    cont();

} // run
void vmmap()
{
    // if a program is not running, you can simply display an error message.
    if (state != RUNNING)
    {
        printf("** program isn't running, please call break after start.\n");
        return;
    }
    string path = "/proc/" + to_string(pinfo->pid) + "/maps";
    ifstream f(path, ios::in);
    if (!f.is_open())
        printf("** vmmap open failed.\n");

    string in = "";
    while (getline(f, in))
    {
        vector<string> line = splitline(in);
        int pos = line[0].find("-");
        string addr2 = line[0].substr(pos + 1);
        line[0].erase(pos);
        string addr1 = line[0];
        cout << setfill('0') << setw(16) << addr1 << "-"
             << setfill('0') << setw(16) << addr2 << " "
             << line[1].substr(0, 3) << " "
             << stoi(line[2]);

        if (line.size() > 5)
            cout << " " << line[5];
        cout << endl;
    }
    f.close();
}
void set(vector<string> line)
{
    if (state != RUNNING)
    {
        printf("** program isn't running, please call break after start.\n");
        return;
    }
    if (line.size() != 3)
    {
        printf("** usage: sdb> set <register name> <value>\n");
        return;
    }

    if (read_reg(pinfo->regs, pinfo->pid))
    {
        long regVal = stol(line[2], NULL, 16);
        set_reg(pinfo->regs, line[1], regVal, pinfo->pid);
    }
}
void si()
{
    if (state != RUNNING)
    {
        printf("** program isn't running, please call break after start.\n");
        return;
    }

    if (ptrace(PTRACE_SINGLESTEP, pinfo->pid, 0, 0) == -1)
    {
        LOGD("[ERROR] sigle step fail\n");
    }
    int status;
    waitpid(pinfo->pid, &status, 0);
    LOGD("[LOGGER] single step success\n");
}
void start()
{
    if (state == RUNNING && !pinfo->terminiated && pinfo->pid != 0)
    {
        printf("** Already started and running a procces ( pid: %d )\n", pinfo->pid);
        return;
    }

    if (state != LOADED)
    {
        printf("** Not loaded program!!\n");
        return;
    }

    if ((pinfo->pid = fork()) < 0)
    {
        printf("fork fail\n");
        return;
    }

    else if (pinfo->pid == 0)
    { // child process
        if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0)
            exit(0);
        if (execvp(pinfo->name, (char *const *)(pinfo->argv)) == -1)
            printf("** %s load fail, %s\n", pinfo->name, strerror(errno));
    }

    else
    {
        int status;
        if (waitpid(pinfo->pid, &status, 0) < 0)
        {
            printf("child error\n");
            return;
        }
        if (WIFSTOPPED(status))
            LOGD("[LOGGER]child stop\n");
        ptrace(PTRACE_SETOPTIONS, pinfo->pid, 0, PTRACE_O_EXITKILL | PTRACE_O_TRACESYSGOOD);
        LOGD("[LOGGER] program has been fork and ready to execute\n");
        printf("** pid %d\n", pinfo->pid);
        state = RUNNING;

        init_start_pinfo(pinfo);
    }
}

/*****************************************
 *
 *             others
 *
 * ***************************************/
vector<string> splitline(string str)
{
    vector<string> ret;
    ret.clear();
    string s = "";

    istringstream in(str);
    while (in >> s)
        ret.push_back(s);

    return ret;
}
bool isRuntime(struct pInfo_t *pinfo)
{
    if (pinfo->pid <= 0)
        return 0;
    return 1;
}
long get_startAddr(pid_t pid)
{
    size_t size = 128;
    char *line = (char *)malloc(sizeof(char) * size);
    char vmmapPath[128] = {'\0'};
    sprintf(vmmapPath, "/proc/%d/maps", pid);
    LOGD("[LOGGER] vmmap path: %s\n", vmmapPath);

    FILE *fp = fopen(vmmapPath, "rb");
    getline(&line, &size, fp);
    LOGD("[LOGGER] vmmap line: %s", line);
    char startAddr[64] = {'\0'};
    sscanf(line, "%[^-]", startAddr);
    LOGD("[LOGGER] start addr: %s\n", startAddr);
    long startAddrNum = strtol(startAddr, NULL, 16);
    LOGD("[LOGGER] addrNum: %lx (%ld)\n", startAddrNum, startAddrNum);

    return startAddrNum;
}

int main(int argc, char **argv)
{
    bool do_load_script_txt = false;
    ifstream ifs;
    state = NOTLOAD;
    pinfo = (struct pInfo_t *)malloc(sizeof(struct pInfo_t));

    // ./hw4 -s scripts/guess.txt sample/guess.nopie 2>&1 | grep -v '^\*\*'
    if (argc > 1 && (strcmp(argv[1], "-s") == 0))
    {
        do_load_script_txt = true;
        ifs.open(argv[2]);
        if (!ifs.is_open())
        {
            printf("script error\n");
            exit(1);
        }
    }
    // ./hw4 [program] or ./hw4 -s [script] [program]
    if (argc == 2 || argc == 4)
    {
        int prgname_index;
        vector<string> show;
        show.push_back("load");
        if (do_load_script_txt)
            prgname_index = 3;
        else
            prgname_index = 1;

        for (; prgname_index < argc; prgname_index++)
            show.push_back(string(argv[prgname_index]));

        load(show);
    }

    while (true)
    {

        string usrinput = "";

        if (do_load_script_txt)
        {
            getline(ifs, usrinput);
            // cout << usrinput << endl;
        }
        else
        {
            printf("sdb> ");
            getline(cin, usrinput);
        }

        if (ifs.eof())
        {
            ifs.close();
            exit(0);
        }

        if (cin.eof())
            exit(0);

        // not empty line
        if (usrinput != "" && (usrinput.find_first_not_of(" \t\r\n") != string::npos))
        {
            LOGD("[LOGGER] usrinput: %s\n", usrinput.c_str());
            vector<string> line = splitline(usrinput); // line[0] is command, after line[0] are all args.
            string cmd = line[0];

            if (cmd == "break" || cmd == "b")
            {
                if (line.size() != 2)
                    printf("** usage: break/b <address>\n");
                else
                    breakpt(line[1]);
            }
            else if (cmd == "cont" || cmd == "c")
            {
                cont();
            }
            else if (cmd == "delete")
            {
                bp_delete(stoi(line[1]));
            }
            else if (cmd == "disasm" || cmd == "d")
            {
                disasm(line);
            }
            else if (cmd == "dump" || cmd == "x")
            {
                dump(line);
            }
            else if (cmd == "exit" || cmd == "q")
            {
                exit(0);
            }
            else if (cmd == "get" || cmd == "g")
            {
                get(line);
            }
            else if (cmd == "getregs")
            {
                getregs();
            }
            else if (cmd == "help" || cmd == "h")
            {
                help();
            }
            else if (cmd == "list" || cmd == "l")
            {
                list(&pinfo->bplist);
            }
            else if (cmd == "load")
            {
                load(line);
            }
            else if (cmd == "run" || cmd == "r")
            {
                run();
            }
            else if (cmd == "vmmap" || cmd == "m")
            {
                vmmap();
            }
            else if (cmd == "set" || cmd == "s")
            {
                set(line);
            }
            else if (cmd == "si")
            {
                si();
            }
            else if (cmd == "start")
            {
                start();
            }
            else
            {
                printf("** Undefined command: \"%s\".  Try \"help\".\n", cmd.c_str());
            }
        }
    }

    return 0;
}