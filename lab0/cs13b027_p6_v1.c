#include<stdio.h>
#include<string.h>
int isPalindrome(char *);
void main(){
  int i,j,k;
  char str[100];
  char *p;
  scanf("%s",str);
  for(i=0;i<strlen(str);i++){
    p=&str[i];
    if(isPalindrome(p))
      break;
  }
  printf("%d",i);
}

int isPalindrome(char *str){
  int i=0;
  for(i=0;i<strlen(str)/2;i++){
    if(str[i]!=str[strlen(str)-1-i])
      return 0;
  }
  return 1;
}