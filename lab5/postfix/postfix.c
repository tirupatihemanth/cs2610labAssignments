/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Postfix Expression Evaluator
 */

#include "Stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int evaluate(int,int,int);
int evaluate_postfix( char* expr );

int main( int argc, char* argv[] )
{
	int ans;
	char expr[100];
	fgets(expr,100,stdin);
	expr[strlen(expr)-1] = '\0';
	ans =evaluate_postfix(expr);
	printf("%d\n",ans);
    return 0;
}

// Implementation of a function which evaluates a postfix function given in the form of a string

int evaluate_postfix(char* expr){

	int i,j,val1, val2, ans, status,opcounter;
	Stack *stack = stack_new();
	char *token, *opers;
	opers="+-*/";
	token = strtok(expr," ");

	while(token!=NULL){
		opcounter =0;
		stack_print(stack);
		status = -1;
		for(i=0;i<3;i++){
			if(strlen(token)==1){
				if((token[0]<48 || token[0]>57) && (token[0]!=42 && token[0]!=43 && token[0]!=45 && token[0]!=47 )){
					printf("INVALID");
					exit(1);
				}
				if(token[0] == opers[i])
					status =i;
				if(strcmp(token,"/")==0)
					status = 3;
			}

		}

		if(strlen(token)!=1){
			for(j=0;j<strlen(token);j++){
				//printf("%d token\n",token[j]);
				if(token[j]<48 || token[j]>57){
					if(token[j]!=42 && token[j]!=43 && token[j]!=45 && token[j]!=47){
						printf("INVALID");
						exit(1);
					}
					else{
						//printf("%d \n",token[j]);
						opcounter++;
						if(opcounter>=2){
							printf("INVALID");
							exit(1);
						}
					}
				}
			}	
			status = -1;
		}
		
		if(status == -1){
			stack_push(stack,atoi(token));
		}
		else{
			val1 = stack_top(stack, &error);
			stack = stack_pop(stack);
			val2 = stack_top(stack, &error);
			stack = stack_pop(stack);
			ans = evaluate(val1,val2,status);
			stack = stack_push(stack,ans);
		}
		token = strtok(NULL," ");

	}
	ans = stack_top(stack, &error);
	return ans;
}

// Implementation of a private function to perform the required operation

int evaluate(int val1, int val2, int status){

	switch(status){
		case 0:
			return val1+val2;
			break;
		case 1:
			return val2-val1;
			break;
		case 2:
			return val1*val2;
			break;
		case 3:
			if(val1 == 0){
				printf("INVALID\n");
				exit(1);
			}
			return val2/val1;
			break;
		default:
			printf("Invalid characters in the postfix expression");
			exit(1);
	}

}
