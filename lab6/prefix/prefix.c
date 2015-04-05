/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Recursive program to evaluate a prefix expression
 *
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "Tokeniser.h"

int evaluate(Token, Token, Token);
int prefix_evaluate(char*, Token, Token);

void print_expression( char* expr )
{
  Token t;
  do
  {
    t = read_token( expr );
    switch( t.op ) {
      // The token is an addition symbol
      case ADD:
        printf( "+ " ); break;
      case SUB:
        printf( "- " ); break;
      case MUL:
        printf( "* " ); break;
      case DIV:
        printf( "/ " ); break;
      // EOE stands for end of expression; Print a new line
      case EOE:
        printf( "\n" ); break;
      // The token is a numeral
      default:
        printf( "%d ", t.num ); break;
    }

  } while( !is_eoe( t ) );

}

// Implementation of the main function which calls the prefix_evaluate function which evaluates the given expression

int main( int argc, char* argv )
{
  char c;
  int len = 1024;
  char expr[len];
  
  // Read the string who's characters need to be counted
  fgets( expr, len, stdin );
  len = strlen( expr );
  if( expr[len-1] == '\n' )
    expr[len-1] = '\0';

 // print_expression( expr );

  Token t1 = read_token(expr);
  Token t2 = read_token(expr);
  int ans = prefix_evaluate(expr, t1, t2);
  printf("%d\n",ans);
  return 0;

}
 
// Implementation of a recursive function to evaluate the given prefix expression

int prefix_evaluate(char * expr, Token t1, Token t2){

  Token t3, valt;
  int val;

  if(is_op(t2)){

    t3 = read_token(expr);
    val = prefix_evaluate(expr,t2,t3);
    valt.op = NOP;
    valt.num = val;
    return prefix_evaluate(expr,t1,valt); 

  }
  Token t4;

  if(!is_op(t2)){
    
    t4 = read_token(expr);
    
    if(!is_op(t4)){

      return evaluate(t1,t2,t4);
    }

  }
  if(is_op(t4)){
    int valb;
    Token t5 = read_token(expr);
    Token valbt;
    valb = prefix_evaluate(expr, t4 , t5);
    valbt.op = NOP;
    valbt.num = valb;
    return evaluate(t1,t2,valbt);
  }


}

// Implemenation of a helper function which evaluates the given prefix expression when two tokens are number and a third one as operator

int evaluate(Token t1, Token t2, Token t3){

  switch(t1.op){

    case ADD:
      return t2.num+t3.num;
      break;
    case SUB:
      return t2.num - t3.num;
      break;
    case 3:
      return t2.num * t3.num;
      break;
    case 4:
      return t2.num / t3.num;
      break;

    }
}


