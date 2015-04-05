#include<stdio.h>
void main(){
  int m,n,temp;
  scanf("%d %d",&m,&n);
  if(m<n){
    temp=m;
    m=n;
    n=temp;
  }
  while(n!=0){
    temp=n;
    n=m%n;
    m=temp;
  }
  printf("%d",m);
}