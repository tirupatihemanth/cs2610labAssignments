#include "mergesort.h"
#include "quicksort.h"
#include <stdio.h>

void main(){
	int n, i;
	scanf("%d",&n);
	int arr1[n],arr2[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr1[i]);
		arr2[i] = arr1[i];
	}

	mergesort(arr1,0,n-1);

	for(i=0;i<n;i++){
		printf("%d ",arr1[i]);
	}
	printf("\n");

	quicksort(arr2,0,n-1);
	
	for(i=0;i<n;i++){
		printf("%d ",arr2[i]);
	}
	printf("\n");

} 
