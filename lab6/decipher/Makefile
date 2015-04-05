#Makefile

CC = gcc

CFLAGS = -g

LDFLAGS = -lm

all: decipher

decipher: decipher.c 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

.PHONY: all clean

clean:

	rm -rf *.o
	rm -rf decipher