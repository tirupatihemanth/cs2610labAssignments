/*
 * Author: Akhilesh (CS10B037)
 */

#ifndef SFQ_H
#define SFQ_H

#include "Queue.h"

typedef struct Stack_from_queue {
    Queue* queue;
} SFQ;

// Create a new empty stack
SFQ* sfq_new();

// Deletes the stack, frees memory.
void sfq_delete( SFQ* st );

// Inserts @val to the top of the stack
SFQ* sfq_push( SFQ* st, int val );

// Remove the element at the top of the stack and puts the removed value into the variable pointed to by x
SFQ* sfq_pop( SFQ* st , int* x );

// Returns the size of the queue
int sfq_size( SFQ* st );

#endif // SFQ_H

