# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: continued-fractions pi

continued-fractions: continued-fractions.o rational.o
	gcc $(LDFLAGS) $^ -o $@

pi: pi.o rational.o
	gcc $(LDFLAGS) $^ -o $@

continued-fractions.o: continued-fractions.c rational.h
	gcc -c $(CFLAGS) $< -o $@

pi.o: pi.c rational.h
	gcc -c $(CFLAGS) $< -o $@

rational.o: rational.c rational.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf continued-fractions pi
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: all
	$(SH) tests/run_tests.sh

