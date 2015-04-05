/*
 * Author: Akhilesh Godi
 * Big Integer test program
 */

#include "BigInt.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

// Reads a single integer argument from the string that's currently being
// parsed using strtok
// Returns 1 on success, and 0 on failure
int read_args1( int* arg1 );

// Reads two integer arguments from the string that's currently being
// parsed using strtok
// Returns 1 on success, and 0 on failure
int read_args2( char* arg1, char* arg2);

int main( int argc, char* argv[] )
{
    char cmd[ BUF_SIZE ];
    // NOTE: Uncomment this once you've implemented this function
       bigint result = init_bigint();
      //bigint result;
    // At the end of every arithmetic operation update the result.

    // In an infinite loop, get input from user
    while( 1 )
    {
        char* op = NULL; // Store the operation
        // Get a line of input from the user
        fgets( cmd, BUF_SIZE, stdin );

        // Parse the line using strtok
        // Note: Given a string like "a b c d", strtok returns "a" the first
        // time it's called, and "b", "c", "d" and NULL subsequently, if the
        // first argument is NULL. Read the manpage for more details
        op = strtok( cmd, " " );
        // If the last line is a new line, make it a null character
        int len = strlen( op );
        if( op[ len-1 ] == '\n' )
          op[ len-1 ] = 0;
        
        // Match the operation, and do appropriate action
        if( strcmp( op, "quit" ) == 0 || op[0] == EOF )
        {
          // Quit when you see this
          break;
        }
        else if( strcmp( op, "set" ) == 0 )
        {
          // set <data>
          // Sets a big int value to data
         
          int data;
          if( read_args1( &data ) )
          {
            // NOTE: This printf line has been added to help debug. Should be
            // removed before submitting
           // printf( "Setting value as %d\n", data );
            // NOTE: Uncomment this once you've implemented this function
             result = int_to_bigint(data);
          }
        }
        
        else if( strcmp( op, "add" ) == 0 )
        {
          // add <num1> <num2> 
          // Adds two bigints and then prints the result
          
          char num1[512];
          char num2[512];
          if( read_args2( num1, num2 ) )
          {
            // NOTE: This printf line has been added to help debug. Should be
            // removed before submitting
            //printf( "Add %s and %s\n", num1, num2 );
            // NOTE: Uncomment this once you've implemented this function
             bigint a = make_bigint(num1);
             bigint b = make_bigint(num2);
             result = bigint_add( a, b);
             print_bigint(result);
          }
        }
        
        else if( strcmp( op, "sub" ) == 0 )
        {
          // sub <num1> <num2> 
          // Subtracts two bigints and then prints the result
          
          char num1[512];
          char num2[512];
          if( read_args2( num1, num2 ) )
          {
            // NOTE: This printf line has been added to help debug. Should be
            // removed before submitting
            //printf( "Subtract %s and %s\n", num1, num2 );
            // NOTE: Uncomment this once you've implemented this function
             bigint a = make_bigint(num1);
             bigint b = make_bigint(num2);
             result = bigint_sub( a, b);
             print_bigint(result);
	     printf("\n");
          }
        }
        
        else if( strcmp( op, "mul" ) == 0 )
        {
          // mul <num1> <num2> 
          // Multiplies two bigints and then prints the result
          
          char num1[512];
          char num2[512];
          if( read_args2( num1, num2 ) )
          {
            // NOTE: This printf line has been added to help debug. Should be
            // removed before submitting
            //printf( "Multiply %s and %s\n", num1, num2 );
            // NOTE: Uncomment this once you've implemented this function
             bigint a = make_bigint(num1);
             bigint b = make_bigint(num2);
             result = bigint_mul( a, b);
             print_bigint(result);
          }
        }
        else if( strcmp( op, "div" ) == 0 )
        {
          // add <num1> <num2> 
          // Adds two bigints and then prints the result
          
          char num1[512];
          char num2[512];
          if( read_args2( num1, num2 ) )
          {
            // NOTE: This printf line has been added to help debug. Should be
            // removed before submitting
            //printf( "Divide %s and %s\n", num1, num2 );
            // NOTE: Uncomment this once you've implemented this function
             bigint a = make_bigint(num1);
             bigint b = make_bigint(num2);
             result = bigint_div( a, b);
             print_bigint(result);
          }
        }
        else
        {
          printf( "Invalid command\n" );
        }

    }

    return 0;
}


// Reads a single integer argument from the string that's currently being
// parsed using strtok
// Returns 1 on success, and 0 on failure
int read_args1( int* arg1 )
{
  char* arg1_str = strtok( NULL, " " );
  if( arg1_str == NULL )
  {
    printf( "Expected 1 argument\n" );
    return 0;
  }
  else
  {
    sscanf( arg1_str, "%d", arg1 );
    return 1;
  }
}

// Reads two string arguments from the string that's currently being
// parsed using strtok
// Returns 1 on success, and 0 on failure
int read_args2(char* arg1, char* arg2)
{
  char* arg1_str = strtok( NULL, " " );
  char* arg2_str = strtok( NULL, " " );
  if( arg1_str == NULL || arg2_str == NULL )
  {
    printf( "Expected 2 arguments\n" );
    return 0;
  }
  else
  {
    sscanf(arg1_str, "%s", arg1);
    sscanf(arg2_str, "%s", arg2);
    return 1;
  }
}

