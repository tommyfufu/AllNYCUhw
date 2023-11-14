#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>
#include "myelf.h"


void show_elf_info( struct elf_t *self ){
	//LOGD("[INFO] is dynamic: %d\n", self->isDynamic);
	printf("** program '%s' loaded. entry point 0x%08lx\n", self->name, self->entry );	
}


int elf_check(char *name ){ // check if user inpu t program is elf
	char magic[5];
	FILE *file = fopen(name, "rb");
	if ( file ) {
		fread( &magic, 5, sizeof(char), file );
		fclose( file );
		if( magic[0]==0x7f && magic[1]=='E' && magic[2]=='L' && magic[3]=='F' ){
			if(magic[4] != 0x02) return NOT_ELF64;
			return OPEN_SUCC;
		} //if
    else 
      return NOT_ELF;
	} // if
  else 
    return OPEN_FAIL;	
} // elf_check


void elf_init( struct elf_t **self, char *name ){
	(*self) = (struct elf_t*)malloc(sizeof(struct elf_t));
	(*self)->name = (char*)malloc(sizeof(char) * strlen(name));
	strcpy((*self)->name, name);
  struct elf64_t elf64;
  elf64_init( &elf64, name );
  elf64_findtextHeader( &elf64 );
  elf64_gettextSection( &elf64 );
  elf64_assign( (*self), &elf64 );

}

void elf64_init( struct elf64_t *elf, char* name ){
	FILE *file = fopen( name, "rb" );
	elf->fp = file;

	// header
	fread( &(elf->header), 1, sizeof( Elf64_Ehdr ), file );

	// get section header str offset & str Header
  // str_shoff = e_shoff + e_shstrndx *sizeof( Elf64_Shdr )
	int str_shoff = elf->header.e_shoff + ( elf->header.e_shstrndx )*sizeof( Elf64_Shdr );
	fseek( file, str_shoff, SEEK_SET );
	fread( &(elf->strHeader), 1, sizeof( Elf64_Shdr ), file );

	LOGD("size: %lx\n", elf->strHeader.sh_size);
	LOGD("offset: %lx\n", elf->strHeader.sh_offset);

	//read str table in str section
	fseek( file, elf->strHeader.sh_offset, SEEK_SET );
	fread( elf->strtab, elf->strHeader.sh_size, sizeof(char), file );
}

void elf64_findtextHeader(struct elf64_t *elf){
	Elf64_Shdr tmpHeader;
	//find .text header
	fseek( elf->fp, elf->header.e_shoff, SEEK_SET );
	for ( int i=0; i < elf->header.e_shnum; i++ ){
		fread( &tmpHeader, 1, sizeof(Elf64_Shdr), elf->fp );	
		if ( strcmp( ( elf->strtab + tmpHeader.sh_name ), ".text" ) == 0){
			elf->textHeader = tmpHeader;
			break;
		}
	}

	Elf64_Phdr pHeader;
	//find .text in thich segment
	fseek( elf->fp, elf->header.e_phoff, SEEK_SET );
	for( int i=0; i < elf->header.e_phnum; i++ ){
		fread( &pHeader, 1, sizeof(Elf64_Phdr), elf->fp );
		if( pHeader.p_vaddr <= elf->textHeader.sh_addr && \
        pHeader.p_vaddr+pHeader.p_memsz > elf->textHeader.sh_addr ){
			elf->text_flag = pHeader.p_flags;
		}
	}
}

void elf64_gettextSection( struct elf64_t *elf ){
	fseek( elf->fp, elf->textHeader.sh_offset, SEEK_SET );
	elf->text_section = (unsigned char*)malloc(sizeof(unsigned char) * elf->textHeader.sh_size) ;
	fread( elf->text_section, elf->textHeader.sh_size, sizeof(char), elf->fp );
}

void elf64_assign( struct elf_t *self, struct elf64_t *elf ){
	self->entry = elf->header.e_entry;
	self->text_addr = elf->textHeader.sh_addr;
	self->text_offset = elf->textHeader.sh_offset;
	self->text_size = elf->textHeader.sh_size;
	self->text_flag = elf->text_flag;
	self->text_section = elf->text_section;
	self->isDynamic = elf->header.e_type==ET_DYN?1:0;
}
