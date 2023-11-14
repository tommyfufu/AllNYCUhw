CC = g++
PROG = hw4
CFLAG = -g -lcapstone -I.

all: $(PROG)

debug: CFLAG += -DDEBUG
debug: $(PROG)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAG)

hw4: sdb.cpp myelf.o myelf.h 
	$(CC) sdb.cpp -o $@ myelf.o $(CFLAG)
.PHONY: clean
clean: 
		rm -rf *.o myelf hw4

