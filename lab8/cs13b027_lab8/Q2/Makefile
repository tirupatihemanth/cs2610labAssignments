#Makefile

CC = gcc

CFLAGS = -g

LDFLAGS = -lm

all: main

main: main.o
	$(CC) $(LDFLAGS) $^ -o $@
main.o: main.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONEY: all clean

clean:

	rm -rf main.o
	rm -rf main
