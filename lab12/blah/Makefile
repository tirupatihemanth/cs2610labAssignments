# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all:
	gcc boxStacking.c quicksort.c -o boxStacking

test: all
	$(SH) tests/run_tests.sh

