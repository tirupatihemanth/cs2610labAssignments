/*
 * Author: Tirupati Hemanth Kumar
 * Big Integer data structure (Implementation)
 */

#include "BigInt.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Additional functions you may need
int max(int a, int b);
int max(int a, int b){
  if(a>b)
    return 1;
  else if(a<b)
    return -1;
  else
    return 0;
}
// int validate_input(char* str);
char* revstr;
void strrev(char*);
void strrev(char *str){
  int i;
  char p[400];
  for(i=0;i<strlen(str);i++)
    p[i]=str[strlen(str)-1-i];
    p[strlen(str)]='\0';
  revstr=p;
}

bigint make_bigint(char* str){
    int i;
    bigint big_num;
    //printf("%s 1\n",str);
    big_num.arr = (char *)malloc(sizeof(char)*(strlen(str)+1));
  if(big_num.arr == NULL){
    printf("Dynamic Memory Allocation could not happen");
    exit(1);
  }
  if(str[0]=='-'){
    big_num.sign=1;
    strrev(str);
    for(i=0;i<strlen(revstr);i++)
      big_num.arr[i]=revstr[i];
    //strcpy(big_num.arr,revstr);
    big_num.arr[strlen(str)-1]='\0';
  }
  else if(str[0]=='+'){
    big_num.sign=0;
    strrev(str);
    for(i=0;i<strlen(revstr);i++)
      big_num.arr[i]=revstr[i];
    //strcpy(big_num.arr,revstr);
    big_num.arr[strlen(str)-1]='\0';
    
  }
  else{
    big_num.sign=0;
    strrev(str);
    //printf("%s 2\n",revstr);
    for(i=0;i<strlen(str);i++)
      big_num.arr[i]=revstr[i];
    //strcpy(big_num.arr,revstr);
    //printf("%s 3\n",big_num.arr);
    big_num.arr[strlen(str)]='\0';
  }
  for(i=strlen(str)-1;i>0;i--){
    if(big_num.arr[i]!='0')
      break;
    if(big_num.arr[i]=='0')
      big_num.arr[i]='\0';
  }
  //printf("%s 4 %d\n",big_num.arr,big_num.sign);
  return big_num;
}

void print_bigint(bigint big_num){
  int i;
  if(big_num.sign==1){
    printf("-");
    for(i=0;i<strlen(big_num.arr);i++)
    printf("%c",big_num.arr[strlen(big_num.arr)-1-i]);
    /*strrev(big_num.arr);
    revstr[strlen(big_num.arr)]='\0';
    char temp[strlen(revstr)];
    strcpy(temp,revstr);
    printf("%s 1\n",temp);*/
  }
  if(big_num.sign==0){
    //printf("+");
    for(i=0;i<strlen(big_num.arr);i++)
    printf("%c",big_num.arr[strlen(big_num.arr)-1-i]);
    //strrev(big_num.arr);
    //revstr[strlen(big_num.arr)]='\0';
    //char temp[strlen(revstr)];
    //strcpy(temp,revstr);
    //printf("%s 2\n",temp);
  }
}

bigint int_to_bigint(int num){
  int i=1,k=0;
  while(num/i!=0){
    i*=10;
    k++;
  }
  char p[k+1];
  sprintf(p,"%d",num);
  return make_bigint(p);
}
bigint init_bigint(){
  return make_bigint("0");
}

int compare_bigint(bigint a,bigint b){
      //printf("%s 9",a.arr);
      int i;
      if(max(b.sign,a.sign))
	return max(b.sign,a.sign);
      else{
	if(max(strlen(a.arr),strlen(b.arr)))
	  return max(strlen(a.arr),strlen(b.arr));
	else{
	  char ptr1[strlen(a.arr)],ptr2[strlen(b.arr)];
	  strrev(a.arr);
	  for(i=0;i<strlen(revstr);i++)
	    ptr1[i]=revstr[i];
	    ptr1[strlen(revstr)]='\0';
	  //strcpy(ptr1,revstr);
	  //printf("%s 7\n",ptr1);
	  strrev(b.arr);
	  for(i=0;i<strlen(revstr);i++)
	    ptr2[i]=revstr[i];
	  ptr2[strlen(revstr)]='\0';
	  //strcpy(ptr2,revstr);
	  //printf("%s 8\n",ptr2);
	  return max(strcmp(ptr1,ptr2),0);
	}
      }
}

bigint zero_adjustment(bigint big_num){
  if(big_num.arr == "0")
    big_num.sign = 0;
}

bigint shift_by_power_of_10(bigint big_num,int d){
  int i;
  void *ptr;
  char str[strlen(big_num.arr)+d];
  strcpy(str,big_num.arr);
  //printf("%s 5",str);
  char newarr[strlen(big_num.arr)+d];
  for(i=0;i<d;i++)
    newarr[i]='0';
  for(i=0;i<strlen(str);i++){
    newarr[i+d]=str[i];
  }
  newarr[strlen(str)+d]='\0';
  big_num.arr=newarr;
  /*
  ptr=realloc(big_num.arr,sizeof(char)*(strlen(big_num.arr)+d));
  if(ptr==NULL){
    printf("realloc failed");
    exit(1);
  }
  for(i=0;i<d;i++)
    big_num.arr[i]='0';
  for(i=0;i<strlen(str);i++){
    big_num.arr[i+d]=str[i];
  }
  big_num.arr[strlen(str)+d]='\0';*/
  //printf("%s 6",big_num.arr);
  return big_num;
}

bigint bigint_add(bigint a,bigint b){
  int i,carry=0;
  char *ptr1,*ptr2;
  if(a.sign>b.sign){
    strrev(a.arr);
    char reva[strlen(revstr)];
    for(i=0;i<strlen(revstr);i++)
      reva[i]=revstr[i];
    reva[strlen(revstr)]='\0';
    bigint bigint_temp = make_bigint(reva);
    bigint_temp.sign=0;
    return bigint_sub(b,bigint_temp);
  }
  else if(a.sign<b.sign){
    //printf("%s %d*",b.arr,strlen(b.arr));
    strrev(b.arr);
    char revb[strlen(revstr)];
    for(i=0;i<strlen(revstr);i++)
      revb[i]=revstr[i];
    revb[strlen(revstr)]='\0';
    //printf("%s %d*\n",revb,strlen(revb));
    //strcpy(revb,revstr);
    bigint bigint_temp = make_bigint(revb);
    bigint_temp.sign=0;
    //printf("**%s %d**\n",bigint_temp.arr,bigint_temp.sign);
    return bigint_sub(a,bigint_temp);
  }
  int k=compare_bigint(a,b);
  if(k==1 || k==0){
    ptr1= (char *)malloc(sizeof(int)*strlen(a.arr));
    ptr2= (char *)malloc(sizeof(int)*strlen(a.arr));
    strcpy(ptr1,a.arr);
    //ptr1[strlen(a.arr)]='\0';
    strcpy(ptr2,b.arr);
  }
  else{
    ptr1= (char *)malloc(sizeof(int)*strlen(b.arr));
    ptr2= (char *)malloc(sizeof(int)*strlen(b.arr));
    strcpy(ptr1,b.arr);
    //ptr1[strlen(b.arr)]='\0';
    strcpy(ptr2,a.arr);
  }
    char p[strlen(ptr1)];
    strcpy(p,ptr2);
    char sum[strlen(ptr1)+2];
    for(i=1;i<=strlen(ptr1)-strlen(ptr2);i++){
      strcat(p,"0");
    }
    //p[i]='\0';
    //printf("%s 10\n",ptr1);
    //printf("%s 11\n",ptr2);
    //printf("%s 12\n",p);
    for(i=0;i<strlen(ptr1);i++){
      //printf("%d :%d\n",ptr1[i]+p[i]-2*'0'+carry,i);
      if((int)(ptr1[i]+p[i]-2*'0'+carry)<=9){
	sum[i]=ptr1[i]+p[i]-'0'+carry;
	//printf("%c ",sum[i]);
        carry=0;
      }
      else{
	sum[i]=ptr1[i]+p[i]+carry-'0'-10;
	//printf("%c ",sum[i]);
	carry=1;
      }
    }
    free(ptr1);
    free(ptr2);
    sum[i]=(char)('0'+carry);
    sum[i+1]='\0';
    //printf("%s 13\n",sum);
    strrev(sum);
    char revsum[strlen(revstr)];
    strcpy(revsum,revstr);
    //printf("%s 14\n",revsum);
    bigint big_sum=make_bigint(revsum);
    big_sum.sign=a.sign;
    //printf("%s 15\n",big_sum.arr);
    return big_sum;
}

bigint bigint_sub(bigint a,bigint b){
   int i,carry=0;
   char *ptr1,*ptr2;
   if(a.sign>b.sign){
    strrev(a.arr);
    char reva[strlen(revstr)];
    for(i=0;i<strlen(revstr);i++)
      reva[i]=revstr[i];
    reva[strlen(revstr)]='\0';
    bigint bigint_temp = make_bigint(reva);
    bigint_temp.sign=0;
    return bigint_add(bigint_temp,b);
  }
  else if(a.sign<b.sign){
    strrev(b.arr);
    char revb[strlen(revstr)];
    for(i=0;i<strlen(revstr);i++)
      revb[i]=revstr[i];
    revb[strlen(revstr)]='\0';
    bigint bigint_temp = make_bigint(revb);
    bigint_temp.sign=0;
    return bigint_add(a,bigint_temp);
  }
     //printf("%d %d %c strlen\n",strlen(a.arr),strlen(b.arr),b.arr[0]);
   int k= compare_bigint(a,b);
   //printf("//%d//\n",k);
   if(k==1){
    ptr1= (char *)malloc(sizeof(int)*strlen(a.arr));
    ptr2= (char *)malloc(sizeof(int)*strlen(a.arr));
    strcpy(ptr1,a.arr);
    //ptr1[strlen(a.arr)]='\0';
    strcpy(ptr2,b.arr);
  }
  else if(k==-1){
    ptr1= (char *)malloc(sizeof(int)*strlen(b.arr));
    ptr2= (char *)malloc(sizeof(int)*strlen(b.arr));
    strcpy(ptr1,b.arr);
    //ptr1[strlen(b.arr)]='\0';
    strcpy(ptr2,a.arr);
  }
  else{
    return make_bigint("0");
  }
  char p[strlen(ptr1)];
    strcpy(p,ptr2);
    char sub[strlen(ptr1)];
    for(i=1;i<=strlen(ptr1)-strlen(ptr2);i++){
      strcat(p,"0");
    }
    //printf("%s 10\n",ptr1);
    //printf("%s 11\n",ptr2);
    //printf("%s 12\n",p);
    for(i=0;i<strlen(ptr1);i++){
      if(ptr1[i]-carry>=p[i]){
	sub[i]=ptr1[i]-carry-p[i]+'0';
	carry=0;
      }
      else{
	sub[i]=ptr1[i]+10-carry-p[i]+'0';
	carry=1;
      }
    }
    free(ptr1);
    free(ptr2);
    sub[i]='\0';
    //printf("%s 14\n",sub);
    strrev(sub);
    char revsub[strlen(revstr)];
    strcpy(revsub,revstr);
    //printf("%s 14\n",revsub);
    bigint big_sub=make_bigint(revsub);
    if(k==-1)
      big_sub.sign=1;
    return big_sub;
}

bigint bigint_mul(bigint a,bigint b){
  int carry=0,k,i,j;
  bigint finalmul,mul;
  mul.sign=0;
  finalmul.sign=0;
  finalmul.arr=(char *)malloc(sizeof(char)*(strlen(a.arr)+strlen(b.arr)+10));
  mul.arr=(char *)malloc(sizeof(char)*(strlen(a.arr)+strlen(b.arr)+10));
  //strcpy(finalmul.arr,"0");
  //strcpy(mul.arr,"0");
  for(i=0;i<strlen(b.arr);i++){
    carry=0;
    for(j=0;j<strlen(a.arr);j++){
      if((b.arr[i]-'0')*(a.arr[j]-'0')+carry<=9){
	mul.arr[j]=(b.arr[i]-'0')*(a.arr[j]-'0')+carry+'0';
	carry=0;
      }
      else{
	mul.arr[j]=(((b.arr[i]-'0')*(a.arr[j]-'0')+carry)%10)+'0';
	carry= ((b.arr[i]-'0')*(a.arr[j]-'0')+carry)/10;
      }
    }
    mul.arr[j]=(char)('0'+carry);
    mul.arr[j+1]='\0';
    //printf("%s 1\n",mul.arr);
    mul= shift_by_power_of_10(mul,i);
    // printf("%s 2\n",mul.arr);
    /*strrev(mul.arr);
    char revmul[strlen(revstr)];
    strcpy(revmul,revstr);
    for(k=0;k<i;k++)
      strcpy(revmul,"0");
    strrev(revmul);
    strcpy(mul.arr,revmul);*/
    // mul.arr[j+1+i]='\0';
    finalmul = bigint_add(finalmul,mul);
  }
  if(a.sign==b.sign)
    finalmul.sign=0;
  else
    finalmul.sign=1;
  //free(mul.arr);
  //printf("%c %c %c %d*\n",finalmul.arr[0],finalmul.arr[1],finalmul.arr[2],finalmul.arr[3]);
  //printf("%s %d %d final\n",finalmul.arr,finalmul.sign,strlen(finalmul.arr));
  return finalmul;
}

bigint bigint_div(bigint a,bigint b){
  int j,sign,i,length,k;
  bigint counter;
  counter = make_bigint("1");
  if(strlen(a.arr)-strlen(b.arr)>=2){
      for(i=0;i<strlen(a.arr)-strlen(b.arr)-1;i++)
	counter=bigint_mul(counter,int_to_bigint(10));
  }
  //print_bigint(counter);
  strrev(a.arr);
  bigint a2 = make_bigint(revstr);
  a2.sign = 0;
  strrev(b.arr);
  bigint b2 = make_bigint(revstr);
  b2.sign = 0;
  if(compare_bigint(b2,make_bigint("0"))==0){
      if(a.sign==1){
	printf("-inf");
	exit(1);
      }
      else{
	printf("inf");
	exit(1);
      }
    }
    if(a.sign==b.sign)
      sign=1;
    else
      sign=-1;
    if(strcmp(a.arr,b.arr)==0){
      return(int_to_bigint(sign));
    }
  while(1){  
    k=compare_bigint(a2,bigint_mul(b2,counter));
    if(k<0){
      //printf("%d finaldiv",i-1);
      //print_bigint(int_to_bigint(sign));
      return bigint_mul(int_to_bigint(sign),bigint_sub(counter,int_to_bigint(1)));
    }
    else if (k==0){
      //printf("%d finaldiv",i);
      //print_bigint(int_to_bigint(sign));
      return bigint_mul(int_to_bigint(sign),counter);
    }
    counter=bigint_add(counter,int_to_bigint(1));
  }
  
}
