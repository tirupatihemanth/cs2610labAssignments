# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: main2 main

main: main.o LList.o
	gcc $(LDFLAGS) $^ -o $@

main.o: main.c LList.h
	gcc -c $(CFLAGS) $< -o $@
 
main2: main2.o polynomial.o LList.o
	gcc $(LDFLAGS) $^ -o $@

main2.o: main2.c polynomial.h
	gcc -c $(CFLAGS) $< -o $@

LList.o: LList.c LList.h
	gcc -c $(CFLAGS) $< -o $@

polynomial.o: polynomial.c polynomial.h
	gcc -c $(CFLAGS) $(LDFLAGS) $< -o $@


.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf main
	rm -rf main2
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: all
	$(SH) tests/run_tests.sh

