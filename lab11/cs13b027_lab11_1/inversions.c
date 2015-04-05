#include <stdio.h>
#include <stdlib.h>

int count = 0;

// private function to implement merging two sets belonging to the same array

void merge(int *ptr1, int left1, int right1, int left2, int right2){

	int i = left1, j=left2, k=0,stat = 0;
	int a[right2 - left1 + 1];

	while(1){

		if(i <= right1 && j <= right2){

			if(ptr1[i] <= ptr1[j]){

				a[k] = ptr1[i];
				k++;
				i++;
				stat = 1;
				continue;

			}
			else{
				a[k] = ptr1[j];
				count+=right1 - i + 1;
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


int main(){

	int n, i;
	scanf("%d",&n);
	int arr[n];

	for(i=0;i<n;i++){
		scanf("%d",arr+i);
	}

	mergesort(arr, 0, n-1);
/*	for(i=0;i<n;i++)
		printf("%d ",arr[i]);*/
	printf("\n%d\n",count);
	return 0;
}
