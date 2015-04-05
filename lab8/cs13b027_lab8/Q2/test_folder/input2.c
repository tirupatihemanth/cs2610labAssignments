#include<stdio.h>
long long int fib(n){if(n==1 || n==0){return 1;	}else return fib(n-1)+fib(n-2);}
int main(){long long int n;scanf("%lld",&n);printf("%lld\n",fib(n));return 0;}
