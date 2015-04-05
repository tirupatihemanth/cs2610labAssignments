#include <stdio.h>
#include <stdlib.h>


void matrix_divide(int **mat1, int **mat2, int **mat3, int **mat4, int **mat, int order){

	for(i=0;i<order/2;i++){
		for(j=0;j<order/2; j++){
			mat1[i][j] = mat[i][j];
			mat2[i][j] = mat[i][j+order/2];
			mat3[i][j] = mat[i+order/2][j];
			mat4[i][j] = mat[i+order/2][j+order/2];
		}
	}
}

int ** matrix_add(int **mat1, int **mat2, int order){

	int **mat, i, j;

	mat = (int **)malloc(sizeof(int *));
	for(i=0;i<order;i++)
		mat[i] = (int *) malloc(sizeof(int)*order);

	for(i=0;i<order;i++){
		for(j=0;j<order;j++){
			mat[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	return mat;
}


int **matrix_recursive(int **mata, int **matb, int order){
	
	if(order == 1){
		int **mat = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat[i] = (int *) malloc(sizeof(int)*order);
		mat[0][0] = mat1[0][0]*mat2[0][0];
		return mat;
	}
	else{

		int **mata11 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mata11[i] = (int *) malloc(sizeof(int)*order);

		int **mata12 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mata12[i] = (int *) malloc(sizeof(int)*order);

		int **mata21 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mata21[i] = (int *) malloc(sizeof(int)*order);

		int **mata22 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mata22[i] = (int *) malloc(sizeof(int)*order);

		int **matb11 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			matb12[i] = (int *) malloc(sizeof(int)*order);

		int **matb12 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat[i] = (int *) malloc(sizeof(int)*order);

		int **matb21 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat[i] = (int *) malloc(sizeof(int)*order);

		int **mat22 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat[i] = (int *) malloc(sizeof(int)*order);

		matrix_divide(mata11, mata12, mata21, mata22, mata, order);
		matrix_divide(matb11, matb12, matb21, matb22, matb, order);

		int **mat1 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat1[i] = (int *) malloc(sizeof(int)*order);

		int **mat2 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat2 = (int *) malloc(sizeof(int)*order);

		int **mat3 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat3[i] = (int *) malloc(sizeof(int)*order);

		int **mat4 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat4[i] = (int *) malloc(sizeof(int)*order);

		int **mat5 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat5[i] = (int *) malloc(sizeof(int)*order);

		int **mat6 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat6[i] = (int *) malloc(sizeof(int)*order);

		int **mat7 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat7[i] = (int *) malloc(sizeof(int)*order);

		int **mat8 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat8[i] = (int *) malloc(sizeof(int)*order);

		mat1 = matrix_recursive(mata11, matb11, order/2);
		mat2 = matrix_recursive(mata12, matb21, order/2);
		mat3 = matrix_recursive(mata11, matb12, order/2);
		mat4 = matrix_recursive(mata12, matb22, order/2);
		mat5 = matrix_recursive(mata21, matb11, order/2);
		mat6 = matrix_recursive(mata22, matb21, order/2);
		mat7 = matrix_recursive(mata21, matb12, order/2);
		mat8 = matrix_recursive(mata22, matb22, order/2);

		int **mat_add1 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat_add1[i] = (int *) malloc(sizeof(int)*order);

		int **mat_add2 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat_add2[i] = (int *) malloc(sizeof(int)*order);

		int **mat_add3 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat_add3[i] = (int *) malloc(sizeof(int)*order);

		int **mat_add4 = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			mat_add4[i] = (int *) malloc(sizeof(int)*order);

		mat_add1 = matrix_add(mat1, mat2, order/2);
		mat_add2 = matrix_add(mat3, mat4, order/2);
		mat_add3 = matrix_add(mat5, mat6, order/2);
		mat_add4 = matrix_add(mat7, mat8, order/2);

		int **matrix = (int **)malloc(sizeof(int *));
		for(i=0;i<order;i++)
			matrix[i] = (int *) malloc(sizeof(int)*order);

		for(i=0;i<order/2;i++){
			for(j=0;j<order/2;j++){
				matrix[i][j] = mat_add1[i][j];
			}
		}

		for(i=0;i<order/2;i++){
			for(j=order/2;j<order;j++){
				matrix[i][j] = mat_add1[i][j-order/2];
			}
		}

		for(i=order/2;i<order;i++){
			for(j=0;j<order/2;j++){
				matrix[i][j] = mat_add1[i-order/2][j];
			}
		}

		for(i=order/2;i<order;i++){
			for(j=order/2;j<order;j++){
				matrix[i][j] = mat_add1[i-order/2][j-order/2];
			}
		}

	}
	return matrix;

}

int main(){

	int n;
	return 0;
}