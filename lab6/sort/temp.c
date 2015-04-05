#include<stdio.h>

void recursion(int);

void main(){

	recursion(10);

}

void recursion(int i){
	int j = 0;
	if(i==0){
		//printf("j: %d, i: %d\n",j,i);
		return;
	}
	j=i;
	recursion(--i);
	printf("j: %d, i: %d\n",j,i);
	
}
