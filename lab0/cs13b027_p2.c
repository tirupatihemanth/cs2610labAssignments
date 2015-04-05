#include<stdio.h>
#include<string.h>
void main(){
  int i;
  char str[100];
  scanf("%s",str);
  char status[26]="00000000000000000000000000";
  for(i=0;i<strlen(str);i++){
    if(status[str[i]-'a']=='0'){
      status[str[i]-'a']='1';
    }
    else{
      printf("%d",0);
      return;
    }
  }
   printf("%d",1);
  //got a warning if used printf(1) but didn't get that warning if used printf(0) and got a segmentation fault on program running
}