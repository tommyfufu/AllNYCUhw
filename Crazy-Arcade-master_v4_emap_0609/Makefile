CC = g++
OBJS = world.cpp room.cpp Bomb.cpp graphic.cpp Player.cpp main.cpp sockop.cpp sem_u.cpp socket_u.cpp
TARGETS = project debuger

all: $(TARGETS)

# $(OBJS).o: $(OBJS).c
# 	$(CC) -c -o $@ $<

project: $(OBJS)
	$(CC) -std=c++11 -o $@ $^ -lncurses -lpthread

debuger: debug_server.cpp sockop.cpp 
	$(CC) -o $@ $^ -lpthread

clean:
# 	rm *.o
	rm $(TARGETS)
