/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Stack data structure (Implementation)
 */

#include "Stack.h"
#include "LList.c"
#include <stdio.h>
#include <stdlib.h>

int error=0;

// Implementation to create a new Stack

Stack* stack_new(){
	Stack *stack;
	stack = (Stack*) malloc(sizeof(Stack));
	stack->front = llist_new();
	return stack;
}

// Implementation to delete a stack

void stack_delete(Stack* stack){
	free(stack->front);
	free(stack);
}

// Implementation of push function for the Stack Data Structure i.e Adding element to the stop of the stack

Stack* stack_push(Stack* stack, int val){
	stack_top(stack,&error);
	llist_prepend(stack->front,val);
	if(error == 1)
		error = 0;
	return stack;
}

// Implementation of pop function for the Stack Data Structure i.e Removing element from the top (LIFO)

Stack* stack_pop(Stack* stack){
	stack_top(stack,&error);
	if(error==1){
		printf("INVALID");
		exit(1);
	}
	else
	llist_remove_first(stack->front);
	return stack;
}

// Implementation to return the element at the top of the stack

int stack_top(Stack* stack,int *error){
	if(stack->front->head == NULL){
		*error = 1;
		return -1;
	}
	else{
		*error = 0;
		return llist_get(stack->front,0);
	}
}

// Implementation to return the size of the stack which is nothing but the size of the linked list 

int stack_size(Stack* stack){
	Stack* newstack;
	newstack = stack_new();
	int count=0;
	while(1){
		stack_top(stack,&error);
		if(error==0){
			stack_push(newstack,stack_top(stack,&error));
			stack_pop(stack);
			count++;
		}
		else
			break;
	}
	while(1){
		stack_top(newstack,&error);
		if(error==0){
			stack_push(stack,stack_top(newstack,&error));
			stack_pop(newstack);
		}
		else
			break;
	}
	return count;
	stack_delete(newstack);
}

// Implementation to print the elements in the stack in the order they are pushed inside but as I was told by akhilesh godi that I should not use linkedlist_print() function I was asked to approach buy using another stack and only push and pops

void stack_print(Stack* stack){

	Stack* newstack;
	newstack = stack_new();
	while(1){
			if(stack_size(stack)!=0){
				stack_push(newstack,stack_top(stack,&error));
				stack_pop(stack);
			}
			else
				break;
	}
	while(1){
		if(stack_size(newstack)!=0){
			printf("%d ",stack_top(newstack,&error));
			stack_push(stack,stack_top(newstack,&error));
			stack_pop(newstack);
		}
		else
			break;
	}
	printf("\n");
	stack_delete(newstack);

}

//Implementation to print the elements in the stack in the order of getting popped out

void stack_reverse_print(Stack* stack){

	Stack* newstack;
	newstack = stack_new();
	while(1){
			if(stack_size(stack)!=0){
				printf("%d ",stack_top(stack,&error));
				stack_push(newstack,stack_top(stack,&error));
				stack_pop(stack);
			}
			else
				break;
	}
	while(1){
		if(stack_size(newstack)!=0){

			stack_push(stack,stack_top(newstack,&error));
			stack_pop(newstack);
		}
		else
			break;
	}
	printf("\n");
	stack_delete(newstack);

}