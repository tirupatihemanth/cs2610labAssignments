#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

// Creates a new qNode with data and next element
qNode* qNode_new(int data, qNode* next){
	qNode *temp = malloc(sizeof(qNode));
	temp->data = data;
	temp->next = next;
	return temp;
}

// Create a new empty queue
Queue* queue_new(){
	Queue *temp = malloc(sizeof(Queue));
	temp->front = NULL;
	temp->rear = NULL;
	return temp;
}

// Deletes the queue, freeing all memory.
void queue_delete( Queue* q ) {
	free(q->front);
	free(q->rear);
	free(q);
}
	
//Inserts val to the rear off the queue.
Queue* enqueue( Queue* q, int val ){
	qNode *temp = qNode_new(val,NULL);
	if(q->front==NULL) {
		q->rear = temp;
		q->front = temp;
	}
	else {
		q->rear->next = temp;
		q->rear = q->rear->next;
	}
	return q;
}

// Returns the element currently at the front of the queue.
int queue_front( Queue* q, int* error ) {
	if(q->front==NULL) {
		*error = 1;
		return 0;
	}
	else {
		*error = 0;
		return q->front->data;
	}
}

// Returns the element currently at the rear end of the queue
int queue_rear( Queue* q, int* error ){
	if(q->rear==NULL) {
		*error = 1;
		return 0;
	}
	else
	{
		*error = 0;
		return q->rear->data;
	}
}

// Deletes the value at the front of the queue. Remember to free memory.
Queue* dequeue( Queue* q ) {
	qNode* temp = q->front;
	q->front = q->front->next;
	free(temp);
	return q;
}

// Returns the number of elements in the queue.
int queue_size( Queue* q ) {
	int count=0;
	qNode *temp = q->front;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}	
	
	

// Iterates over the entire queue, printing its elements one by one - separated by spaces.
void queue_print( Queue* q ) {
	qNode *temp = q->front;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}



