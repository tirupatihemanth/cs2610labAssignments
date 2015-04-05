/*
 * Author: mentors
 * Polynomial data structure
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "LList.h"
  
typedef struct polynomial_
{
    LList* pHead;
} polynomial;

// Construct a polynomial from a list of 'n' coefficients stored in 'coeffs'.
polynomial polynomial_construct ();

// Print the polynomial q in the format a0 x^0 + a1 x^1 ...
void print_polynomial ( polynomial p );

// Evaluate the polynomial p at the value x
double polynomial_evaluate ( polynomial p, double x );

// Operations on polynomials
polynomial add_polynomial ( polynomial p, polynomial q );
polynomial subtract_polynomial ( polynomial p, polynomial q );     // subtracts q from p

polynomial differentiate ( polynomial p );
polynomial integrate ( polynomial p );

#endif // POLYNOMIAL_H

