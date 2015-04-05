#include<unistd.h>
#include<sys/time.h>
#include<stdio.h>
void time_me(int);
void main(){
      int i;
      struct timeval tv1,tv2;
      time_t beftime,aftime;
      gettimeofday(&tv1,NULL);
      beftime = tv1.tv_sec;
      int n;
      scanf("%d",&n);
      for(i=1;i<=10;i++){
	time_me(n);
      }
      gettimeofday(&tv2,NULL);
      aftime=tv2.tv_sec;
      printf("%f\n",(aftime-beftime)/10.0);
}
void time_me(int N) {
    int i;
    int a=0;
    sleep(2);
    if (N > 3) {
        sleep((N-2)%7);
    }
    for( i=1; i < 73638; i++) {
        a += i;
    }
    a = ~a;
}