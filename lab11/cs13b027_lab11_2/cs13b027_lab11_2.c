#include <stdio.h>
#include <stdlib.h>


// can be further improvised without even using matrix_add by just giving matrix_multiply third argument matC and other required paraameters similar to matrix_add and using in the base case += instead of just = i.e increment instead of assignment 


void matrix_add(int **matA, int **matB, int **matC, int i3, int j3, int order){

	int i,j;
	for(i=0;i<order;i++){
		for(j = 0;j<order;j++){
			matC[i3+i][j3+j] += matA[i][j]+matB[i][j];
		}
	}
}


int ** matrix_multiply(int **matA, int i1, int j1, int **matB, int i2, int j2, int order){
	
	int i,j;
	int **matC = (int **) malloc(sizeof(int *)*order);

	for(i=0;i<order;i++)
		matC[i] = (int *) malloc(sizeof(int)*order);
	for(i=0;i<order;i++){
		for(j=0;j<order;j++){
			matC[i][j] = 0;
		}
	} 

	if(order == 1){
		matC[0][0] = matA[i1][j1]*matB[i2][j2];
		return matC;
	}
	else{

			matrix_add(matrix_multiply(matA, i1, j1, matB, i2, j2, order/2),matrix_multiply(matA, i1, j1+order/2, matB, i2+order/2, j2, order/2), matC, 0,0,order/2);
			matrix_add(matrix_multiply(matA, i1, j1, matB, i2, j2+order/2, order/2), matrix_multiply(matA, i1, j1+order/2, matB, i2+order/2, j2+order/2, order/2), matC, 0,order/2,order/2);
			matrix_add(matrix_multiply(matA,i1+order/2,j1,matB,i2,j2,order/2),matrix_multiply(matA,i1+order/2,j1+order/2,matB,i2+order/2,j2,order/2),matC,order/2,0,order/2);
			matrix_add(matrix_multiply(matA, i1+order/2,j1,matB,i2,j2+order/2,order/2),matrix_multiply(matA,i1+order/2,j1+order/2,matB,i2+order/2,j2+order/2,order/2),matC,order/2,order/2,order/2);
	}
	return matC;

}


int main(){

	int n,i,j;
	scanf("%d",&n);

	int **matA = (int **) malloc(sizeof(int *)*n);
	int **matB = (int **) malloc(sizeof(int *)*n);

	for(i=0;i<n;i++)
		matA[i]= (int *) malloc(sizeof(int)*n);
	
	for(i = 0;i<n;i++)
		matB[i] = (int *) malloc(sizeof(int)*n);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matA[i][j]);
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matB[i][j]);
		}
	}

	int **matC = matrix_multiply(matA, 0, 0, matB, 0, 0, n);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",matC[i][j]);
		}
		printf("\n");
	}
	return 0;
}
