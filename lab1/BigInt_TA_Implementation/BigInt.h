/*
 * Author: Akhilesh Godi (CS10B037)
 * Template code for Big Integer Library
 * CS2110 - Computer Programming Lab - Lab 1 (Structures)
 */
#ifndef BIGINT_H
#define BIGINT_H

typedef struct bigint_ {

	char* value;//stores the number in a dynamic array. The string only contains the numbers and nothing else. No trailing 0's in the beginning. 0th index stores the Left most number. The [length-1] index stores the right most number.
	int length;//Length stores the length of the ABSOLUTE value of a number and also excludes the null character in the count.
				//So -0000123123 has length 6. Length even excludes the starting 0's which don't matter.
	int pos;//pos is 1 if the number is positive, else 0.

} bigint;

// Parse a string to make it a Big Integer
bigint make_bigint(char* str);

// Prints a Big Integer
void print_bigint(bigint big_num);

// Converts an integer to a bigint
bigint int_to_bigint(int num);

// Initialize a bigint to zero
bigint init_bigint();

// Compares two bigints and returns 0 if equal, +1 if a > b and -1 if a < b
int compare_bigint(bigint a, bigint b);

// Zero justify a number. Makes -0 in the result to +0 if bigint's valuation is
// zero.
bigint zero_adjustment(bigint big_num);

// Multiply a big int with 10^d. 'd' is positive.
bigint shift_by_power_of_10(bigint big_num, int d);

// Adds two bigints and returns the result which is a bigint
bigint bigint_add(bigint a, bigint b);

// Subtracts two bigints and returns the result which is a bigint
bigint bigint_sub(bigint a, bigint b);

// Multiplies two big ints and returns a bigint
bigint bigint_mul(bigint a, bigint b);

// Divides two bigints and returns a bigint similar to 9/4 = 2
bigint bigint_div(bigint a, bigint b);

#endif // BIGINT_H
