#include <stdio.h>

#define EOE -1 // end of expression
#define NOP 0 // Used with numbers
#define ADD 1 // +
#define SUB 2 // - 
#define MUL 3 // *
#define DIV 4 // /

void main(){

	typedef struct Token_{
		
		char op;
		int num;

	} Token;
	Token t = {EOE,0};
	printf("%d \n",t.op);
}