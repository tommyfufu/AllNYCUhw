FINAL=libmini
SRC_FILE=$(basename $(notdir $(filter-out libmini.c, $(wildcard *.c))))
OBJ_FILE=$(patsubst %.asm, %.o, $(wildcard *.asm)) libmini.o
ARCHIVE=$(FINAL).a
SO_FILE=$(FINAL).so

CFLAG=-c -g -Wall -fno-stack-protector -nostdlib
CFLAG1=-fPIC
CFLAG2=-I. -I.. -DUSEMINI
CC=gcc
AS=yasm
AFLAG=-f elf64 -DYASM -D__x86_64__ -DPIC

LD_SRC=libmini.a start.o -L. -L..
LFLAG=-m elf_x86_64 --dynamic-linker /lib64/ld-linux-x86-64.so.2


all: $(ARCHIVE) $(SO_FILE) $(OBJ_FILE) $(SRC_FILE)

$(ARCHIVE): libmini64.o libmini.o
	ar rc $@ $^

$(SO_FILE): libmini64.o libmini.o
	ld -shared $^ -o $@


%.o: %.asm
	$(AS) $(AFLAG) $< -o $@

%.o: %.c
	$(CC) $(CFLAG) $(CFLAG1) $< -o $@

%: %.c
	$(CC) $(CFLAG) $(CFLAG2) $< -o $@.o
	ld $(LFLAG) -o $@ $@.o $(LD_SRC)

clean:
	rm -rf $(OBJ_FILE) $(ARCHIVE) $(SO_FILE) $(SRC_FILE)
