/*
 * Author: 
 * Tokenises a postfix expression string
 */

#ifndef TOKENISER_H
#define TOKENISER_H

// Used to define the token type
#define EOE -1 // end of expression
#define NOP 0 // Used with numbers
#define ADD 1 // +
#define SUB 2 // - 
#define MUL 3 // *
#define DIV 4 // /

// the input is broken up into tokens, which can either be numbers or
// operations (+,-,*,/)
 
typedef struct Token_ {
  char op;
  int num;
} Token;

// Helper functions
int is_eoe( Token t );
int is_op( Token t );
int is_add( Token t );
int is_sub( Token t );
int is_mul( Token t );
int is_div( Token t );
int get_val( Token t );

// Reads a single token from the input
Token read_token( char* expr );

#endif // TOKENISER_H

