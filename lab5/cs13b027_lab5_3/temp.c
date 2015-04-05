#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
void main(){
	Stack * stack = stack_new();
	stack_push(stack,5);
	stack_push(stack,3);
	stack_push(stack,9);
	stack_print(stack);
	printf("%d stack_size\n",stack_size(stack));
	stack_pop(stack);
	stack_print(stack);
	printf("%d stack_size\n",stack_size(stack));
	stack_print(stack);
	stack_pop(stack);
	printf("%d stack_size\n",stack_size(stack));
	stack_print(stack);
	stack_pop(stack);
	printf("%d stack_size\n",stack_size(stack));
	
}