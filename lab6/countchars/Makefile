#Makefile

CC = gcc

LDFLAGS = -lm

CFLAGS = -g

all: main

main: main.c
	$(CC) $(LDFLAGS)  $^ -o $@ 


.PHONY: all clean

clean:

	rm -rf main.o
	rm -rf main