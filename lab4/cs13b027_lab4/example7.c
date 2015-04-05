/*
 * Jojo (CS10B061)
 * Prints a string in reverse but only alphabets with even ascii
 * "abhik" should give "hb"
 * Buggy implementation
 */
#include<stdio.h>
#include<stdlib.h>

void reverse_print(char* x){
	if(x[0] == '\0'){
		return;
	}
	reverse_print(++x);
	if(x[0] % 2==0)
		printf("%c",x[0]);
	return;
}
int main()
{
    char *x =malloc(100);
    scanf("%s",x);
	int i;
	reverse_print(x);	
	printf("\n");	 	
		
}
