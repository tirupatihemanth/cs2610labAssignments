/*
 * Complex Number Library
 * Arun Chaganty (CS07B023)
 * This file contains a simple library to deal with complex numbers
 */

// This prevents this .h file from being added many times.
#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex {
    double re;
    double im;
} complex;

complex complex_new( double re, double im );
void complex_print( complex z );
double complex_mag( complex x );
double complex_phase( complex x );

complex complex_add( complex x, complex y );
complex complex_sub( complex x, complex y );
complex complex_mul( complex x, complex y );
complex complex_div( complex x, complex y );


#endif // COMPLEX_H

