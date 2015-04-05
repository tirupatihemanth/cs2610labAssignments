#Makefile

CC = gcc

CFLAGS = -g

LDFLAGS = -lm

all: sort

sort: sort.o mergesort.o quicksort.o
	$(CC) $(LDFLAGS) $^ -o $@ 

sort.o: sort.c quicksort.h mergesort.h
	$(CC) -c $(CFLAGS) $< -o $@

quicksort.o:quicksort.c quicksort.h
	$(CC) -c $(CFLAGS) $< -o $@

mergesort.o: mergesort.c mergesort.h
	$(CC) -c $(CFLAGS) $< -o $@

.PHONEY: all clean

clean:
	
	rm -rf *.o
	rm -rf sort
