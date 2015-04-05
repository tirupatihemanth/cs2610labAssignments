#include<stdio.h>
#include<string.h>
void main(){
  int i;
  int status[58]={0};
  char str1[100];
  char str2[100];
  scanf("%s%s",str1,str2);
  if(strlen(str1)==strlen(str2)){
    for(i=0;i<strlen(str1);i++){
    status[str1[i]-'A']+=1;
    status[str2[i]-'A']-=1;
  }
  for(i=0;i<58;i++){
    if(status[i]!=0){
      printf("%d",0);
      return;
    }
  }
    printf("%d",1);
  }
  else 
    printf("%d",0);
  
}