#Makefile

all: queue

CC = gcc

LDFLAGS = -lm

CFLAGS = -g

all: queue

queue: main.o Queue.o
	$(CC) $(LDFLAGS) $^ -o $@

main.o: main.c Queue.h
	$(CC) -c $(CFLAGS) $< -o $@

Queue.o: Queue.c Queue.h
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: all clean

clean:
	rm -rf *.o
	rm -rf queue