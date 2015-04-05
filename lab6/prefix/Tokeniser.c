/*
 * Name (Roll No.)
 * Recursive program to evaluate a postfix expression
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Tokeniser.h"

#define CHUNK 1024

// Helper functions
int is_eoe( Token t ) { return t.op == EOE; }
int is_op( Token t ) { return t.op != NOP; }
int is_add( Token t ) { return t.op == ADD; }
int is_sub( Token t ) { return t.op == SUB; }
int is_div( Token t ) { return t.op == DIV; }
int is_mul( Token t ) { return t.op == MUL; }

int get_val( Token t )
{
  assert( t.op == NOP );
  return t.num;
}

Token make_token( char* tok )
{
  if( tok == NULL )
  {
    Token t = { EOE, 0 };
    return t;
  }
  else if( strcmp( tok, "+" ) == 0 )
  {
    Token t = { ADD, 0 };
    return t;
  }
  else if( strcmp( tok, "-" ) == 0 )
  {
    Token t = { SUB, 0 };
    return t;
  }
  else if( strcmp( tok, "*" ) == 0 )
  {
    Token t = { MUL, 0 };
    return t;
  }
  else if( strcmp( tok, "/" ) == 0 )
  {
    Token t = { DIV, 0 };
    return t;
  }
  else
  {
    int num = atoi( tok );
    Token t = { NOP, num };
    return t;
  }
}

Token read_token( char* expr )
{
  // NOTE: This is dangerous, but unavoidable because of the way strtok
  // works.
  static char has_seen_before = 0;
  char* tok;

  if( has_seen_before ) expr = NULL;
  else has_seen_before = 1;

  tok = strtok( expr, " " );

  return make_token( tok );
}

