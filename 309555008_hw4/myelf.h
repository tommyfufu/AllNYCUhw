#ifndef MYELF_H
#define MYELF_H
#include <elf.h>

#ifdef DEBUG
	#define LOGD(...) printf(__VA_ARGS__)
#else
	#define LOGD(...)
#endif

struct elf64_t{
	FILE *fp;
	Elf64_Ehdr header;      /* The ELF file header.  This appears at the start of every ELF file.  */
	Elf64_Shdr strHeader;   /* string Section header.  */
	Elf64_Shdr textHeader;  /* text Section header.  */
	char strtab[65535];	    // store string table
	long text_flag;
	unsigned char *text_section;
	
};

struct elf_t{
	char *name;
	unsigned long entry;
	unsigned long text_addr;
	unsigned long text_offset;
	unsigned long text_size;
	long text_flag;
	unsigned char *text_section;
	int isDynamic;
};
// hw4 only test elf64
int elf_check( char *name );
//ret
#define OPEN_SUCC   0
#define OPEN_FAIL   1
#define NOT_ELF     2
#define NOT_ELF64   3
//type
#define ELF64 1
void elf_init(struct elf_t **self, char *name );
void show_elf_info(struct elf_t *self);
void show_elf_text_range(struct elf_t *self);

void elf64_init(struct elf64_t *elf, char* name);
void elf64_findtextHeader(struct elf64_t *elf);
void elf64_gettextSection(struct elf64_t *elf);
void elf64_assign(struct elf_t *self, struct elf64_t *elf);
#endif