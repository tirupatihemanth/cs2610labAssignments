/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Linked list test program
 */
 
#include "polynomial.h"
#include <stdio.h>

int main()
{

	polynomial expression;
	polynomial differential;
	polynomial integral;
	polynomial sum;
	polynomial diff;
	//Read polynomial

	expression = polynomial_construct();
	printf("\n");
	//print_polynomial(expression);
	//printf("\n");
	//Calculate and print differential
	
	differential = differentiate(expression);
	print_polynomial(differential);
	printf("\n");

	//Calculate Integral
	
	integral = integrate(expression);
	print_polynomial(integral);
	printf("\n");

	//Calculate sum of differential and integral
	
	sum = add_polynomial(differential,integral);
	print_polynomial(sum);
	printf("\n");

	//Calculate difference between differential and integral

	diff = subtract_polynomial(differential,integral);
	print_polynomial(diff);

}
