/*
 * 	Jojo (CS10B061)
 *	
 *	Evaluates max-min of the array of numbers
 * 	Buggy Implementation	
 *	
 */

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int len;
	scanf("%d",&len);    
	int *arr = (int *) malloc(len*sizeof(int));	
	int i,j;	
	for(j=0;j<len;j++){
		scanf("%d",&arr[j]);
	}	
	int max=0;
	int min=arr[0];	
	for(i=0;i<len;i++){
		if(arr[i] > max)
			max=arr[i];
		if(arr[i] < min)
			min=arr[i];
	}    
	printf("%d\n",max-min);
}
