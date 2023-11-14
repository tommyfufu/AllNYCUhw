CC = g++
PROG = hw4
CFLAG = -g -lcapstone 

all: $(PROG)

debug: CFLAG += -DDEBUG
debug: $(PROG)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAG)

hw4: sdb.cpp myelf.o myelf.h 
	$(CC) sdb.cpp -o $@ myelf.o $(CFLAG)
