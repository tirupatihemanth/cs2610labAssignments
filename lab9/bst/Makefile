# Makefile
#

CC = gcc
SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: token

token: token.o BSTree.o
	$(CC) $(LDFLAGS) $^ -o $@
	
# Queue.o: Queue.c Queue.h LList.h
# 	$(CC) -c $(CFLAGS) $^ -o $@

# LList.o: LList.c LList.h
# 	$(CC) -c $(CFLAGS) $^ -o $@

token.o: token.c BSTree.h
	$(CC) -c $(CFLAGS) $< -o $@

BSTree.o: BSTree.c BSTree.h
	$(CC) -c $(CFLAGS) $< -o $@

# Write Makefile rules to compile the main program, token, as well as
# the BSTree library

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf token
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: all
	$(SH) tests/run_tests.sh

