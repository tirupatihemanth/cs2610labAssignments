# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: postfix

postfix: postfix.o Stack.o
	gcc $(LDFLAGS) $^ -o $@

postfix.o: postfix.c Stack.h
	gcc -c $(CFLAGS) $< -o $@

Stack.o: Stack.c Stack.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf postfix
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: all
	$(SH) tests/run_tests.sh

