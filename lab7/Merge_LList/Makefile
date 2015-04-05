# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: main

main: main.o LList.o
	gcc $(LDFLAGS) $^ -o $@

main.o: main.c LList.h
	gcc -c $(CFLAGS) $< -o $@

LList.o: LList.c LList.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint

clean:
	rm -rf *.o
	rm -rf main
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

