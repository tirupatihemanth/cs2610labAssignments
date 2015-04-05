/*
 * Author: Tirupati Hemanth kumar
 * Finding the factorial of large numbers
 */

#include "BigInt.h"
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) {
  int n,i;
  scanf("%d",&n);
  bigint num,temp;
  char str[2]="1";
  num=make_bigint(str);
  //printf("%s %d %d\n",num.arr,strlen(num.arr),num.sign);
  //print_bigint(num);
  //printf("\n");
  for(i=1;i<=n;i++){
    temp=int_to_bigint(i);
    num=bigint_mul(num,temp);
    //num.arr[strlen(num.arr)]='\0';
    //print_bigint(num);
  }
  //num.arr[strlen(num.arr)]='\0';
  //printf("%d\n",strlen(num.arr));
  //printf("%s\n",num.arr);
  print_bigint(num);
  return 0;
}
