/*
 * Author: Tirupati Hemanth Kumar
 * Rational data structure
 */

#ifndef RATIONAL_H
#define RATIONAL_H

typedef struct rational_ {
  int num,den;
} rational;

// Make a rational value
rational make_rational ( int p, int q );
// Parse a rational value from a string
rational rational_parse ( char* str ) ;
// Print a rational value
void rational_print ( rational q ) ;
// Convert p to a rational p/1
rational rational_from_int ( int p ) ;

// Convert rational to double
double rational_to_double ( rational p ) ;

// Operations on rational numbers
rational rational_add ( rational p, rational q ) ;
rational rational_sub ( rational p, rational q ) ;
rational rational_mul ( rational p, rational q ) ;
rational rational_div ( rational p, rational q ) ;
rational rational_reciprocate( rational p ) ;

#endif // RATIONAL_H

