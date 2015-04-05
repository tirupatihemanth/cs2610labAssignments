#include<stdio.h>
#include<string.h>

int makeSubstrings(int);

char str1[100],str2[100];

void main(){
  int i,j;
  int status;
  scanf("%s%s",str1,str2);
  if(strlen(str1)==strlen(str2) && strcmp(str1,str2)!=0){
    for(i=0;i<strlen(str2);i++){
    if(str2[i]==str1[0]){
      status=makeSubstrings(i);
    }
    if(status==1){
      printf("%d",1);
      return;
    }
  }
  printf("%d",0);
  }
  else if(strcmp(str1,str2)==0){
    printf("%d",1);
  }
  else printf("%d",0);
}




int makeSubstrings(int i){
  char substr1[100]="",substr2[100]="";
  int j;
  for(j=0;j<i;j++){
    substr1[j]=str2[j];
  }
  int temp;
  j=0;
  for(temp=i;temp<strlen(str2);temp++){
    substr2[j]=str2[temp];
    j++;
  }
  
  if(strstr(str1,substr1)!=NULL && strstr(str1,substr2)!=NULL){
    return 1;
  }
  else return 0;
}