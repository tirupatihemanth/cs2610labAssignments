/*
 * Name: Tirupati Hemanth Kumar
 * Roll NO.: cs13b027
 * advanced partitioning
 */

#include <stdio.h>
#include <stdlib.h>

void print_array(int, int*);
void partition( int n, int* arr )
{
/*  int temp[3] = {0},i;
  for(i=0;i<n;i++){
	temp[arr[i]]++;
  }
 // printf("%d %d %d\n",temp[0],temp[1],temp[2]);
  for(i=0;i<temp[0];i++){
	arr[i] = 0;
  }
  for(;i<temp[0]+temp[1];i++){
	arr[i] = 1;
  }
  for(;i<temp[0]+temp[1]+  temp[2];i++){
	arr[i] = 2;
  }*/
  // TODO: Write your function here

	int left = 0,i, right = n-1,temp;
	for(i=0;i<n;i++)
	{
		if(i > right)
			break;
		if(arr[i] == 0){
			arr[i] = arr[left];
			arr[left] = 0;
			left++;
		}
		else if(arr[i] == 2){
			arr[i] = arr[right];
			arr[right] = 2;
			right--;
			i--;
		}


		//print_array(n,arr);
	}

}

void print_array( int n, int* arr )
{
  int i;
  for( i = 0; i < n; i++ )
  {
	printf( "%d ", arr[i] );
  }
  printf( "\n" );
}

int main()
{
  int i, n;
  int* arr;
  // Read a count n, and a stream of integers
  scanf( "%d", &n );
  arr = (int*) malloc( sizeof(int) * n );
  for( i = 0; i < n; i++ )
	scanf( "%d", &arr[i] );

  partition( n, arr );
  print_array( n, arr );
  
  return 0;
}

