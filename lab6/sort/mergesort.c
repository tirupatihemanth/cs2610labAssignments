/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Implementation of the mergesort algorithm
 *
 */

// Implementation for the mergesort algorithm


#include "mergesort.h"

void  mergesort(int *ptr, int left, int right){

	//int *ptr1,*ptr2;

	if(left!=right){

		mergesort(ptr, left, (left+right)/2);
		mergesort(ptr, ((left+right)/2)+1, right);

	}

	if(left == right){

		return;

	}

	 merge(ptr, left, (left+right)/2, ((left+right)/2 )+1, right);

}

// private function to implement merging two sets belonging to the same array

void merge(int *ptr1, int left1, int right1, int left2, int right2){

	int i = left1, j=left2, k=0;
	int a[right2 - left1 + 1 ];
	while(1){
		if(i <= right1 && j <= right2){

			if(ptr1[i] <= ptr1[j]){

				a[k] = ptr1[i];
				k++;
				i++;
				continue;

			}
			else{
				a[k] = ptr1[j];
				j++;
				k++;
				continue;
			}
		}
		if(i <= right1){
			a[k] = ptr1[i];
			k++;
			i++;
			continue;
		}
		else if(j <= right2){
			a[k] = ptr1[j];
			k++;
			j++;
			continue;
		}
		else
			break;

	}

	for(i=left1,j=0;i<=right1;i++,j++)
		ptr1[i] = a[j];
	
	for(i = left2,j; i<= right2; i++,j++)
		ptr1[i] = a[j];

}
