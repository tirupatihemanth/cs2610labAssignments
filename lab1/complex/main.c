/*
 * Fun with Complex Numbers
 * Arun Chaganty (CS07B023)
 * Lets do fun things with complex numbers
 */

#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

int main( int argc, const char* argv[] )
{
    double re, im,x,y,x1,y1,x2,y2;
    // The input is argc, argv
    if( argc != 3 )
    {
        printf( "Usage: %s <re> <im>", argv[0] );
        exit( EXIT_FAILURE );
    }
    // Lets find the magnitude of a complex number 
    re = atof( argv[1] );
    im = atof( argv[2] );
    printf( "%f\n", complex_mag( complex_new( re, im ) ) );
    printf("Enter the two complex numbers as <re1> <im1> <re2> <im2>:\n");
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    //complex_print(complex_add(complex_new(x1,y1),complex_new(x2,y2)));
    //complex_print(complex_sub(complex_new(x1,y1),complex_new(x2,y2)));
    //complex_print(complex_mul(complex_new(x1,y1),complex_new(x2,y2)));
    //complex_print(complex_div(complex_new(x1,y1),complex_new(x2,y2)));
    return EXIT_SUCCESS;
}

