#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char set[5]={'I','V','X','L'};
int value(char);
int indexOf(char);
int stat=0;
void main(){
 char str[10];
 int a=0,b=0,i;
 int ans=0,temp=1;
 scanf("%s",str);
 char add[10]="\0",sub[10]="\0";
 for(i=0;i<strlen(str)-3;i++){
   if(str[i]==str[i+1]&&str[i+1]==str[i+2]&&str[i+2]==str[i+3]){
     printf("INVALID");
     exit(1);
  }
}
 add[a++]=str[strlen(str)-1];
 add[a]='\0';
 for(i=strlen(str)-2;i>=0;i--){
   if(indexOf(str[i])>indexOf(str[i+1])){
     temp=1;
     add[a++]=str[i];
     add[a]='\0';
  }
  else if(indexOf(str[i])<indexOf(str[i+1])){
    temp=0;
    sub[b++]=str[i];
    sub[b]='\0';
  }
  else{
    
    if(temp==0){
       printf("INVALID3");
      exit(1);
      //sub[b++]=str[i];
      //sub[b]='\0';
  }
    else
      add[a++]=str[i];
      add[a]='\0';
  }
    
    
}
  printf("%s  ",add);
  printf("%s  ",sub);
  for(i=0;i<strlen(add);i++){
    ans+=value(add[i]);
  }
  for(i=0;i<strlen(sub);i++){
    if(sub[i]=='V' || sub[i]=='L'){
      printf("INVALID2");
      exit(1);
     }
    ans-=value(sub[i]);
  }
  printf("%d",ans);
}



int indexOf(char c){
  int i;
  for(i=0;i<strlen(set);i++){
    if(set[i]==c)
      return i;
  }
  return 0;
}

int value(char c){
  switch(c){
    case 'I':
      return 1;
      break;
    case 'V':
      return 5;
      break;
    case 'X':
      return 10;
      break;
    case 'L':
      return 50;
      break;
    default:
      printf("INVALID1");
      exit(1);
  }
}
