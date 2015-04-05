#include<stdio.h>
void main(){
  int m,n,k,i,j;
  scanf("%d %d",&m,&n);
  int mat[m][n];
  char row[m];
  char col[n];
  
  for(i=0;i<m;i++)
    row[i]='1';
  
  for(i=0;i<n;i++)
    col[i]='1';
  
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      scanf("%d",&k);
      mat[i][j]=k;
      if(k==0){
	row[i]='0';
	col[j]='0';
      }
    }
  }
  
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(row[i]=='0' || col[j]=='0')
	printf("0\t");
      else printf("%d\t",mat[i][j]);
    }
    printf("\n");
  }
}