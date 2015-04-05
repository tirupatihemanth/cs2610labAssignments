/*
* Box stacking algorithm
* Name: Tirupati Hemanth Kumar
* Roll Number: cs13b027
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"

void sort_permute(int permute [][3], int final_permute[][3], int stat[], int basearea, int k){

	int i=0;
	while(1){
		if((permute[i][0]*permute[i][1] == basearea) && (stat[i] == 0)){
			stat[i] = 1;
			final_permute[k][0] = permute[i][0];
			final_permute[k][1] = permute[i][1];
			final_permute[k][2] = permute[i][2];
			return;
		}
		i++;
	}
}


int main(){

	int i,j,n;
	scanf("%d",&n);
	int **mat = (int **) malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
		mat[i] = (int *) malloc(sizeof(int)*3);

	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			scanf("%d",&mat[i][j]);
		}
	}

	int permute[3*n][3];

	for(i=0;i<3*n;i++){
		
		if(i%3 == 0){

			permute[i][0] = mat[i/3][0];
			permute[i][1] = mat[i/3][1];
			permute[i][2] = mat[i/3][2];

		}

		if(i%3 == 1){

			permute[i][0] = mat[i/3][2];
			permute[i][1] = mat[i/3][1];
			permute[i][2] = mat[i/3][0];

		}

		if(i%3 == 2){

			permute[i][0] = mat[i/3][0];
			permute[i][1] = mat[i/3][2];
			permute[i][2] = mat[i/3][1];

		}

	}


	int basearea[3*n];
	int final_permute[3*n][3];
	for(i=0;i<3*n;i++){
		basearea[i] = permute[i][0]*permute[i][1];
	}

	quicksort(basearea, 0, 3*n-1);

	int stat[3*n];
	for(i=0;i<3*n;i++){
		stat[i] = 0;
	}
	int heights[3*n];

	for(i=0;i<3*n;i++)
		sort_permute(permute, final_permute, stat, basearea[i], i);

	for(i=0;i<3*n;i++)
		heights[i] = final_permute[i][2];

	for(i=1;i<3*n; i++){
		for(j=0;j<i;j++){

			if((final_permute[j][0]>final_permute[j][1]?final_permute[j][1]:final_permute[j][0]) < (final_permute[i][0]>final_permute[i][1]?final_permute[i][1]:final_permute[i][0]) && (final_permute[j][0]>final_permute[j][1]?final_permute[j][0]:final_permute[j][1])< (final_permute[i][0]>final_permute[i][1]?final_permute[i][0]:final_permute[i][1]) && heights[i]< heights[j] + final_permute[i][2])
				heights[i] = heights[j] + final_permute[i][2];
		}
	}
int max = heights[0];
	for(i=0;i<3*n;i++){
		if(heights[i]>max)
			max = heights[i];
	}
	printf("%d",max);

	return 0;
}

