CC = gcc
CFLAGS =-I.
game:
	$(CC) -o game game.c $(CFLAGS)
	$(CC) -o guess guess.c $(CFLAGS)

.PHONY: clean
clean: 
		rm -rf *.o game guess
