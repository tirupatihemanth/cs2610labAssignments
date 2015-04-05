
/*
 *	Author:Jojo(CS10B061)
 *
 *	Input has to be alphabets only
 * 	Output is just the case change of each input character 
 *	i.e. JOjo becomes joJO
 *	
 *	Buggy Implementation
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *x =malloc(100);
    scanf("%s",x);
	int i;
	for(i=0;i<strlen(x);i++){
			if( (x[i] <= 'a' && x[i] >='z') || (x[i] <= 'A' && x[i] >='Z')){
				printf("Error\n");
				return 0;
			}		
	}

	for(i=0;i<strlen(x);i++){
		if( x[i] >= 'a' )	{
			x[i]= 'A' + (x[i]-'a');
		}
		else{
			x[i]='a'+ (x[i] - 'A');			
		}
	}
	printf("%s\n",x	);
}
