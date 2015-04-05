#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

void main(){
	Queue* queue = queue_new();
	printf("enqueue 1\n");
	queue = enqueue(queue,1);
	printf("%d queue_size\n",queue_size(queue));
	queue_print(queue);
	printf("enqueue 2\n");
	queue = enqueue(queue,2);
	printf("%d queue_size\n",queue_size(queue));
	queue_print(queue);
	printf("enqueue 3\n");
	queue = enqueue(queue,3);
	printf("%d queue_size\n",queue_size(queue));
	queue_print(queue);
	int val1 = queue_front(queue,&error);
	int val2 = queue_rear(queue,&error);
	printf("%d is front %d is rear\n",val1, val2);
	printf("dequeue 1\n");
	queue = dequeue(queue);
	queue_print(queue);
	printf("%d queue_size\n",queue_size(queue));
	val1 = queue_front(queue,&error);
	val2 = queue_rear(queue,&error);
	printf("%d is front  %d is rear\n",val1, val2);
	printf("dequeue 2\n");
	queue = dequeue(queue);
	queue_print(queue);
	printf("%d queue_size\n",queue_size(queue));
	val1 = queue_front(queue,&error);
	val2 = queue_rear(queue,&error);
	printf("%d is front  %d is rear\n",val1, val2);
	val1 = queue_front(queue,&error);
	val2 = queue_rear(queue,&error);
	printf("dequeue 3\n");
	dequeue(queue);
	queue_delete(queue);

}