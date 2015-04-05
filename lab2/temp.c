#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void main(){
	//printf("%d\n",sizeof(char*));
	//printf("%d\n",time(NULL));
	//printf("%ld\n",RAND_MAX);
	char str[5];
	strcpy(str,"hello");
	str[0]=49;
	printf("%s",str);


}
