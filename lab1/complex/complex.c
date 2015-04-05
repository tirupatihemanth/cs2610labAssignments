/*
 * Complex Number Library
 * Arun Chaganty (CS07B023)
 * This file contains a simple library to deal with complex numbers
 */

#include <stdio.h>
#include <math.h>
#include "complex.h"

complex complex_new( double re, double im )
{
    complex z;
    z.re = re;
    z.im = im;
    return z;
}

void complex_print( complex z )
{
    printf( "%lf + i%lf", z.re, z.im );
}

double complex_mag( complex x )
{
    return sqrt( x.re * x.re + x.im * x.im );
}

complex complex_add( complex x, complex y )
{
    complex z = complex_new( x.re + y.re, x.im + y.im );
#ifdef DEBUG
    printf( "Added two numbers\n" );
    complex_print( x );
    printf( "\n" );
    complex_print( y );
    printf( "\n" );
#endif
    return z;
}
complex complex_sub(complex x,complex y){
    complex z = complex_new(x.re-y.re,x.im-y.im);
    return z;
}
complex complex_mul(complex x, complex y){
    complex z = complex_new(x.re*y.re-x.im*y.im, x.im*y.re+x.re*y.im);
    return z;
}
complex complex_div(complex x, complex y){
    int ratio = complex_mag(x)/complex_mag(y);
    complex z = complex_new(ratio*cos(atan(x.im/x.re)-atan(y.im/y.re)),ratio*cos(atan(x.im/x.re)-atan(y.im/y.re))); 
}

