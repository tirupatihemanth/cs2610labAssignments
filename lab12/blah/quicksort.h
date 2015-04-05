/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Header file for the quicksort.c
 *
 */ 

#ifndef QUICKSORT_H
#define QUICKSORT_H

void quicksort(int *, int, int);
void reorder(int *, int, int, int);
int pivot_index(int *, int, int, int);

#endif