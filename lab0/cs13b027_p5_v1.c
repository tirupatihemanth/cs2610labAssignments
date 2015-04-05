#include<stdio.h>
#include<string.h>
void main(){
  char str1[100],str2[100],str3[200];;
  scanf("%s %s",str1,str2);
  //printf("%s %s",str1,str2);
  strcpy(str3,str2);
  strcat(str3,str2);
  if(strstr(str3,str1)!=NULL){
    printf("%d",1);
  }
  else printf("%d",0);
}