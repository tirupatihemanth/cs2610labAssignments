#include<stdio.h>
#include<string.h>
void strrev(char *);
void main(){
  char str[100];
  scanf("%s",str);
  strrev(str);
}
void strrev(char *str){
  if(strlen(str)==0)
    return;
  printf("%c",str[strlen(str)-1]);
  str[strlen(str)-1]='\0';
  strrev(str);
}