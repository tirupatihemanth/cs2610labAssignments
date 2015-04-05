# Author: Tirupati Hemanth Kumar
# Roll No.: cs13b027

#Compiler used
CC = gcc

#DEBUGGING FLAGS
DEBUG = -DDEBUG

#different cflags used for comilation

CFLAGS = -g 

#Linking flags

LDFLAGS = -lm

#The way we compile depends on the below code

all: movie_theatre

movie_theatre: Stack.o movie_theatre.c
	$(CC) $(DEBUG) $(LDFLAGS)  $^ -o $@

Stack.o: Stack.c Stack.h	
	$(CC) -c $(CFLAGS) $< -o $@

movie_theatre.o: movie_theatre.c Stack.h
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: all clean

clean:
	rm -rf *.o
	rm movie_theatre
