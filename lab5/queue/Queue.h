/*
 * Author: 
 * Stack data structure
 */

#include "LList.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue_ {
	LList* front;
	Node* back;
} Queue;

extern int error;

// Create a new empty stack
Queue* queue_new();

// Deletes the queue, freeing all memory.
void queue_delete( Queue* q );

//Inserts val to the rear of the queue.
Queue* enqueue( Queue* q, int val );

// Returns the element currently at the front of the queue.
int queue_front( Queue* q, int* error ); 

// Returns the element currently at the rear end of the queue
int queue_rear( Queue* q, int* error );

// Deletes the value at the front of the queue. Remember to free memory.
Queue* dequeue( Queue* q );

// Returns the number of elements in the queue.
int queue_size( Queue* q );

// Iterates over the entire queue, printing its elements one by one - separated by spaces.
void queue_print( Queue* q );


#endif // QUEUE_H

