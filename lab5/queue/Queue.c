/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Stack data structure (Implementation) using linked lists
 */

#include "LList.c"
#include "Queue.h"
#include<stdio.h>
#include<stdlib.h>

int error =0;

//Implementation to create a new queue

Queue* queue_new(){
	Queue* queue;
	queue = (Queue* ) malloc(sizeof(Queue));
	queue->front = llist_new();
	queue->back = NULL;
	return queue;
}

// Impelementation to delete the entire queue

void queue_delete( Queue* q ){
	free(q->front);
	free(q->back);
	free(q);
}

//Implementation to add and element to the queue (enqueue)

Queue* enqueue( Queue* q, int val ){
	queue_front(q,&error);
	llist_append(q->front,val);
	if(llist_size(q->front)==1)
		q->back = q->front->head;
	if(llist_size(q->front)>=2)
		q->back = q->back->next;
	if(error == 1)
		error = 0;
	return q;
}

// Implementation to get the front element of the queue front element of the queue is element that will be removed on dequeue

int queue_front( Queue* q, int* error ){

	 if(q->front->head == NULL){
	 	*error = 1;
	 	return -1;
	 }
	 else{
	 	*error = 0;
	 	return llist_get(q->front,0);
	 }

}

// Implementation to return the element at the back of the queue is at the opposite end to the front end of the queue

int queue_rear(Queue* q, int* error){
	if(q->back== NULL){
	 	*error = 1;
	 	return -1;
	 }
	 else{
	 	*error = 0;
		return q->back->data;
	}
}

// Impelements the dequeue operation i.e using first in first out procedure

Queue* dequeue( Queue* q ){
	if(error ==1){
		printf("INVALID");
		exit(1);
	}
	llist_remove_first(q->front);
	return q;
}

// Implementation to return the number of elements in the queue.

int queue_size( Queue* queue ){

	Queue* newqueue = queue_new();
	int count =0;
	while(1){
			queue_front(queue,&error);
			if(error==0){
				enqueue(newqueue, queue_front(queue,&error));
				dequeue(queue);
				count++;
			}
			else
				break;
	}
	while(1){
		queue_front(newqueue,&error);
		if(error==0){
			enqueue(queue, queue_front(newqueue,&error));
			dequeue(newqueue);
		}
		else
			break;
	}
	return count;
	queue_delete(newqueue);
}

// Impelementation to iterate over the entire queue, printing its elements one by one - separated by spaces in the order in which the elements are enqueued

void queue_print( Queue* queue ){
	
	Queue* newqueue = queue_new();

	while(1){
			if(queue_size(queue)!=0){
				printf("%d ",queue_front(queue,&error));
				enqueue(newqueue, queue_front(queue,&error));
				dequeue(queue);
			}
			else
				break;
	}
	while(1){

		if(queue_size(newqueue)!=0){
			enqueue(queue, queue_front(newqueue,&error));
			dequeue(newqueue);
		}
		else
			break;
	}
	printf("\n");
	queue_delete(newqueue);
}

