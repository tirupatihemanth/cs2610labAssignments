#include "BigInt.h"
#include<stdio.h>
void main(){
	char ptr1[10],ptr2[10];
	scanf("%s %s",ptr1,ptr2);
//	print_bigint(bigint_div(make_bigint(ptr1),make_bigint(ptr2)));	
//	print_bigint(int_to_bigint(10));
	bigint_mul(make_bigint(ptr1),make_bigint(ptr2));
//	printf("%s",val.arr);
	//print_bigint(bigint_add(make_bigint(ptr1),make_bigint(ptr2)));
//	int k=compare_bigint(make_bigint(ptr),make_bigint(ptrr));
//	printf("%d",k);
//	print_bigint(make_bigint(ptr));
//	print_bigint(shift_by_power_of_10(make_bigint(ptr),2));
}
