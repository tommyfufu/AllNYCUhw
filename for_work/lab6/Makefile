CC = gcc
CFLAGS =-I.
lab4:
	$(CC) -pthread -o server server.c $(CFLAGS)
	$(CC) -pthread -o client server.c $(CFLAGS)

.PHONY: clean
clean: 
		rm -rf *.o server client


		
