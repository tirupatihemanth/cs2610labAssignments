/*
 * Author: <Name> <Roll Number>
 */

#include "QFS.h"
#include <stdio.h>
#include <stdlib.h>

//Implementation for the new queue from stack

QFS* qfs_new(){

	QFS* qfs = (QFS* ) malloc(sizeof(QFS));
	qfs->stack = stack_new();
	return qfs;
}

//Implementation to delete the new queue made from stack

void qfs_delete(QFS* qfs){
	stack_delete(qfs->stack);
	free(qfs);
}

//Implementation to the enqueue

QFS* qfs_enqueue( QFS* q, int val ){
	stack_push(q->stack,val);
	return q;
}

//Implementation to the dequeue

QFS* qfs_dequeue(QFS* q,int* x){
	int error;
	Stack * newstack = stack_new();
	int i,size = stack_size(q->stack);
	for(i=0;i<size;i++){
		stack_push(newstack,stack_top(q->stack,&error));
		stack_pop(q->stack);
	}
	*x = stack_top(newstack,&error);
	stack_pop(newstack);
	size = stack_size(newstack);
	for(i=0;i<size;i++){
		stack_push(q->stack,stack_top(newstack,&error));
		stack_pop(newstack);
	}
	stack_delete(newstack);
	return q;
}

//Implementation to return size of the queue

int qfs_size(QFS* q){
	return stack_size(q->stack);
}

