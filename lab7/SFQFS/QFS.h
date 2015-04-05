/*
 * Author: Akhilesh (CS10B037)
 */

#ifndef QFS_H
#define QFS_H

#include "Stack.h"

typedef struct Queue_From_Stack {
    Stack* stack;
} QFS;

// Create a new empty queue from stacks
QFS* qfs_new();

// Deletes the queue, frees memory.
void qfs_delete( QFS* q );

// Adds val into the queue in a FIFO fashion 
QFS* qfs_enqueue( QFS* q, int val );

// Removes an element from the queue and puts the value in the value pointed to by x
QFS* qfs_dequeue( QFS* q, int* x );

// Returns the size of the queue
int qfs_size(QFS* q);

#endif // QFS_H

