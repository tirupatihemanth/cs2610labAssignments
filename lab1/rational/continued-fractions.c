/*
 * Author: Tirupati Hemanth Kumar
 * Compute continued fractions
 */
#include<stdio.h>
#include "rational.h"
//rational continue_fraction(int*,int);

int main( int argc, char* argv[] )
{
    int arr[4],i;
    scanf("%d%d%d%d",&arr[0],&arr[1],&arr[2],&arr[3]);
    rational ans=rational_from_int(arr[3]);
    for(i=2;i>=0;i--){
      //rational_print(rational_from_int(arr[i]));
      //rational_print(rational_reciprocate(ans));
      ans=rational_add(rational_from_int(arr[i]),rational_reciprocate(ans));
      //rational_print(ans);
    }
    //rational_print(ans);
    printf("%f\n",rational_to_double(ans));
    //rational_print(continue_fraction(arr,0));
    //printf("%f\n",rational_to_double(continue_fraction(arr,0)));
    //printf("%lf\n",rational_to_double(continue_fraction(arr,0)));
    //printf("%f",rational_to_double(rational_parse(p)));
    return 0;
}

/*rational continue_fraction(int *arr,int i){
  rational_print(rational_from_int(arr[i]));
  //rational_print(rational_add(rational_from_int(arr[i]),rational_reciprocate(rational_from_int(arr[i+1]))));
  if(i==3)
    return rational_from_int(arr[3]);
  else {
    return rational_add(rational_from_int(arr[i]),rational_reciprocate(continue_fraction(arr,++i)));
  }
}
*/