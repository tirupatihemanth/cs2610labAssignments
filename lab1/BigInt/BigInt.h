/*
 * Author: Akhilesh Godi (CS10B037)
 * Template code for Big Integer Library
 * CS2110 - Computer Programming Lab - Lab 1 (Structures)
 */
#ifndef BIGINT_H
#define BIGINT_H

typedef struct bigint_ {
    char *arr;
    short int sign;
    // What all do you need here?
    // Maybe a character array to store the digits? [Assume max digits is 512]
    // Instead of having a fixed size array, you can dynamically allocate too.
    // You need to also take care of the size of the number
    // Remember that we could possibly have both signed and unsigned numbers so
    // you might want to have another field for that?
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

// Multiply a big int with 10^d
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
