#include<stdio.h>
#include<string.h>
char revdupsuffix[100];
int l=0;
void strrev(char*);
void main(){
  int i=0;
  char str[100],dup[100];
  scanf("%s",str);
  strcpy(dup,str);
  char dupsuffix[100];
  char suffix[100]="";
  if(!isPalindrome(str)){
    for(i=0;i<strlen(str)-1;i++){
      suffix[i]=str[i];
      strcpy(dupsuffix,suffix);
      l=0;
      strrev(dupsuffix);
      strcpy(dup,str);
      strcat(dup,revdupsuffix);
      //printf("%s ",dup);
      if(isPalindrome(dup))
	break;
    }
    printf("%d",i+1);
  }
  else
    printf("%d",0);
}

int isPalindrome(char *str){
  int i=0;
  for(i=0;i<strlen(str)/2;i++){
    if(str[i]!=str[strlen(str)-1-i])
      return 0;
  }
  return 1;
}
void strrev(char *str){
  if(strlen(str)==0)
    return;
  revdupsuffix[l]=str[strlen(str)-1];
  l++;
  str[strlen(str)-1]='\0';
  strrev(str);
}
