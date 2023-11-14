#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/user.h>
#include <elf.h>
#include <inttypes.h>
#include <capstone/capstone.h>
#include <sstream>
#include "myelf.h"
using namespace std;


#define HELPMSG "\
- break {instruction-address}: add a break point\n\
- cont: continue execution\n\
- delete {break-point-id}: remove a break point\n\
- disasm addr: disassemble instructions in a file or a memory region\n\
- dump addr [length]: dump memory content\n\
- exit: terminate the debugger\n\
- get reg: get a single value from a register\n\
- getregs: show registers\n\
- help: show this message\n\
- list: list break points\n\
- load {path/to/a/program}: load a program\n\
- run: run the program\n\
- vmmap: show memory layout\n\
- set reg val: get a single value to a register\n\
- si: step into instruction\n\
- start: start the program and stop at the first instruction\n"
#define CHK_REG( name ) \
	if( targetReg == #name ){\
		printf("%s = %lld (0x%llx)\n", #name, regs->name, regs->name);\
		return;}
    
#define SET_REG(name)\
	if( targetReg ==  #name ){\
		regs->name = regVal;\
		if( ptrace(PTRACE_SETREGS, pid, 0, regs) == 0 ) return;\
		else LOGD("[ERROR] set register fail\n"); return;}

#define BUFFERSIZE 32
#define DISASM_SUCC 0
#define CSH_FAIL	1
#define DISASM_FAIL 2
#define DISASM_SUCC 0
#define CSH_FAIL	1
#define DISASM_FAIL 2

enum sdbstate
{
    NOTLOAD = 0,
    LOADED,
    RUNNING,
    ANY,
};

struct pInfo_t
{
    pid_t pid;
    char name[64];
    char argv[16][16];
    bool terminiated;

    struct breakpointList_t *bplist;
    struct dump_t *dumpinfo;
    struct elf_t *elf;
    struct disasm_t *disasm;
    struct user_regs_struct *regs;
};
struct dump_t
{
    unsigned long long dumpAddr;
    char dumpChar[16];
};

struct breakpointList_t
{
    unsigned long long address;
    long code;
    struct breakpointList_t *next;
};

struct disasm_t
{
    size_t instrId;
    size_t instrSize;
    cs_insn *insn;
};
/*****sdb cmd*****/
void breakpt(string addr);
void cont();
void bp_delete( int id );
void dump( vector<string> line );
void get(vector<string> line);
void getregs();
void help();
void list(struct breakpointList_t **self);
void load(vector<string> cmd);
void run();
void vmmap();
void set(vector<string> line);
void si();
void start();
/*****breakpoint*****/
void bp_store( struct breakpointList_t **self, unsigned long long address, long code);
long bp_get_code(struct breakpointList_t **self, unsigned long long stopaddr);
bool bp_recover(struct breakpointList_t **self, int id, pid_t pid);
long bp_set( unsigned long long addrPos, struct pInfo_t *pinfo );
void bp_delete( int id );
bool bp_isinlist( struct breakpointList_t **self, unsigned long long rip );
/*****dump*****/
void dump_init(struct dump_t **self, unsigned long long addr);
void dump_show( struct dump_t *self, pid_t pid );
/*****reg*****/
bool read_reg(struct user_regs_struct *regs, pid_t pid);
void set_reg(struct user_regs_struct *regs, string targetReg, long regVal, pid_t pid);
/*****disasm*****/
int disasm_init(struct disasm_t **self, unsigned char* code, int size, long addrNum);
int disasm_textInit(struct pInfo_t *pinfo, long addr);
void disasm_show( struct disasm_t *self );
int disasm_word(unsigned char* code, long addrNum, char **buffer);
long disasm_runtime( long addrNum, pid_t pid );
/*****start*****/
void init_bp_to_start(struct pInfo_t *pinfo);
void init_regs(struct user_regs_struct **regs);
void init_start_pinfo(struct pInfo_t *pinfo);
/*****others*****/
vector<string> splitline(string str);
bool isRuntime(struct pInfo_t *pinfo);
long get_startAddr(pid_t pid);
