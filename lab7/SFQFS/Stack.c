/*
 * Author: <Name> <Roll Number>
 * Stack data structure (Implementation)
 */

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new empty stack
Stack* stack_new(){
	Stack *new = (Stack *) malloc(sizeof(Stack));
	new->lst = llist_new();
	return new;
}

// Deletes the stack, frees memory.
void stack_delete( Stack* st ){
	free(st->lst);
	free(st);
}

// Inserts @val to the top of the stack
Stack* stack_push( Stack* st, int val ){
	st->lst = llist_prepend(st->lst,val);
	return st;
}

// Remove the element at the top of the stack - also frees memory
Stack* stack_pop( Stack* st ){
	st->lst = llist_remove_first(st->lst);
	return st;
}

// Returns the element currently at the top of the stack. If the stack is empty,
// @error should be set to 1, else 0.
int stack_top( Stack* st, int* error ){
	if(st->lst->head==NULL) {
		*error = 1;
		return 0;
	}
	else
	{
		*error = 0;
		return st->lst->head->data;
	}
}

// Returns the number of elements in the stack
int stack_size( Stack* st ){
    return llist_size(st->lst);
}

// Prints the elements currently in the stack
void stack_print( Stack* st ){
    llist_print(st->lst);	
}
	
	
