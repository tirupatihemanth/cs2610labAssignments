/*
*
* Floyd Warshall shortest path algorithm
* Name: Tirupati Hemanth Kumar
* Roll Number: cs13b027
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main(int argc, char** argv){

	int n, i, j,k;
	scanf("%d",&n);
	int **wMat, **dMat;
	char str[4];

	int INF = INT_MAX;

	wMat = (int **) malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
		wMat[i] = (int *)malloc(sizeof(int)*n);

	dMat = (int **) malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
		dMat[i] = (int *)malloc(sizeof(int)*n);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%s",str);
			if(strcmp(str, "INF") == 0)
				wMat[i][j] = INF;
			else
				wMat[i][j] = atoi(str);
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			dMat[i][j] =  wMat[i][j];
		}
	}

	for(k=1;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				
				if(dMat[i][k]!= INF && dMat[k][j]!= INF &&(dMat[i][j]>(dMat[i][k]+dMat[k][j])))
					dMat[i][j] = dMat[i][k] + dMat[k][j];

			}
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(dMat[i][j] == INF)
				printf("INF\t");
			else
				printf("%d\t",dMat[i][j]);
		}
		printf("\n");
	}

	return 0;
}
