# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: main factorial

main: main.o BigInt.o
	gcc $(LDFLAGS) $^ -o $@
	
factorial: factorial.o BigInt.o
	gcc $(LDFLAGS) $^ -o $@

main.o: main.c BigInt.h
	gcc -c $(CFLAGS) $< -o $@

factorial.o: factorial.c BigInt.h
	gcc -c $(CFLAGS) $< -o $@

BigInt.o: BigInt.c BigInt.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf main factorial
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: all
	$(SH) tests/run_tests.sh

