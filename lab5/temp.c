#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include <string.h>

void main(){
	char* token;
	FILE *fp;
	char expr[100];
	char file[6];
	scanf("%s",file);
	fp = fopen( file, "r");
	if(fp == NULL){
		printf("Cannot Open the input file\n");
		exit(1);
	}
	fgets(expr,100,fp);
	printf("%d",strlen(expr));
	expr[strlen(expr)-1] = '\0';
	printf("%s expr \n",expr);
	token = strtok(expr," ");
	while(token != NULL){
		printf("%s token\n",token);
		token = strtok(NULL," ");
	}
//	int error=0;
//	Stack *stack;
//	stack = stack_new();
//	stack_push(stack,1);
//	int top = stack_top(stack,&error);
//	printf("Top1 : %d\n",top);
//	stack_push(stack,2);
//	top = stack_top(stack,&error);
//	printf("Top2 : %d\n",top);
//	stack_push(stack,3);
//	top = stack_top(stack,&error);
//	printf("Top3: %d\n",top);

//	stack_print(stack);
	

//	stack_pop(stack);
//	top = stack_top(stack,&error);
//	printf("Top1 : %d\n",top);
//	stack_pop(stack);
//	top = stack_top(stack,&error);
//	printf("Top2 : %d\n",top);
//	stack_pop(stack);
//	top = stack_top(stack,&error);
//	printf("Top3: %d\n",top);

//	stack_print(stack);
}
