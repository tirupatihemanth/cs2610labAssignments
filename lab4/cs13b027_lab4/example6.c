/*
 * Jojo (CS10B061)
 * Insertion Sort 
 * Take length of list to be sorted as first input
 *	Followed by list of numbers
 * Output should be sorted list	
 */

#include <stdio.h>
#include <stdlib.h>

void print_array( int n, int* arr )
{
  int i;
  for( i = 0; i < n; i++ )
  {
    printf( "%d ", arr[i] );
  }
  printf( "\n" );
}

void insertion_sort( int n, int* arr ){
    int i,j,Temp;
    for(i=1; i<n; i++)
	{
		Temp = arr[i];
		j = i-1;
		while(Temp<arr[j] && j>=0)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = Temp;
	}

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

  insertion_sort( n, arr );
  print_array( n, arr );
  
  return 0;
}

