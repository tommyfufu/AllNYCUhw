CC = gcc
CFLAGS =-I.
lab4:
	$(CC) -o server server.c sockop.c $(CFLAGS)
	$(CC) -o client server.c sockop.c $(CFLAGS)

.PHONY: clean
clean: 
		rm -rf *.o server client


		
