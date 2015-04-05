# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: main

main: main.o LList.o Stack.o Queue.o QFS.o SFQ.o
	gcc $(LDFLAGS) $^ -o $@

main.o: main.c QFS.h SFQ.h Stack.h Queue.h
	gcc -c $(CFLAGS) $< -o $@

SFQ.o: SFQ.c SFQ.h Queue.h 
	gcc -c $(CFLAGS) $< -o $@
    
QFS.o: QFS.c QFS.h Stack.h
	gcc -c $(CFLAGS) $< -o $@

Queue.o: Queue.c Queue.h
	gcc -c $(CFLAGS) $< -o $@

Stack.o: Stack.c Stack.h LList.h
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
