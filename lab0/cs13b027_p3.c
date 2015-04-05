#include<stdio.h>
int M,N;
void setRowZero(int (*)[N],int);
void setColZero(int (*)[N],int);
void main(){
  int i,j,k;
  scanf("%d%d",&M,&N);
  int mat[M][N],mat1[M][N];
  for(i=0;i<M;i++){
    for(j=0;j<N;j++){
      scanf("%d",&k);
      mat[i][j]=k;
      mat1[i][j]=k;
      }
    }
     for(i=0;i<M;i++){
      for(j=0;j<N;j++){
	if(mat[i][j]==0){
	  setRowZero(mat1,i);
	  setColZero(mat1,j);
	}
      }
     }
    for(i=0;i<M;i++){
      for(j=0;j<N;j++){
	printf("%d \t",mat1[i][j]);
      }
      printf("\n");
    }
  }
  
void setRowZero(int (*mat)[N],int row){
  int i;
  for(i=0;i<N;i++)
    mat[row][i]=0;
}
void setColZero(int (*mat)[N],int col){
  int i;
  for(i=0;i<M;i++){
    mat[i][col]=0;
  }
}
