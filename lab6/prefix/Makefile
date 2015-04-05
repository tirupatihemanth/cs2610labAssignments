# Makefile
#

CC = gcc
SH = bash
CFLAGS = -g
LDFLAGS = -lm

PROG = prefix

all: $(PROG)

$(PROG): $(PROG).o Tokeniser.o 

$(PROG).o: $(PROG).c Tokeniser.h

Tokeniser.o: Tokeniser.c Tokeniser.h

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf tests/*_
	rm -rf $(PROG)

lint:

test: all
	$(SH) tests/run_tests.sh

