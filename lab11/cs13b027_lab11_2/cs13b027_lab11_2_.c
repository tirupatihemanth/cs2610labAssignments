#include <stdio.h>
#include <stdlib.h>

int n;

void evaluate_basecase(int mat1[][n], int mat2[][n], int starti, int startj, int startk, int mat3[][n]){
	
	int i,j,k;
	for(i=starti;i<=starti+1;i++){
		for(j=startj;j<=startj+1;j++){
			for(k=startk;k<=startk+1;k++){
				mat3[i][j]+=mat1[i][k]*mat2[k][j];
			}
		}
	}

}

int main(){
	int i,j,k;
	scanf("%d",&n);
	int mat1[n][n];
	int mat2[n][n];
	int mat3[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",*(mat1+i)+j);
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",*(mat2+i)+j);
			mat3[i][j] = 0;
		}
	}

	for(i=0;i<n;i+=2){
		for(j=0;j<n;j+=2){
			for(k=0;k<n;k+=2){
				evaluate_basecase(mat1, mat2, i, j, k, mat3);
			}
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",mat3[i][j]);
		}
		printf("\n");
	}


	return 0;
}
