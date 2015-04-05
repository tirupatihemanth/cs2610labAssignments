# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all:
	gcc $(CFLAGS) $(LDFLAGS) -o boxStacking boxStacking.c

clean:
	rm -rf *.o
	rm -rf tests/*_
	rm -rf boxStacking

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: all
	$(SH) tests/run_tests.sh

