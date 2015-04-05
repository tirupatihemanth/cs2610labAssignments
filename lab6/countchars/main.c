/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Counting number of occurences of a c in a string using tail recursion
 *
 */

#include <stdio.h>
#include <string.h>

int countchar(char *, char, int);

void main(){

	char str[100];
	char c;
	c = getchar();
	getchar();
	gets(str);
	//printf("%s\n",str);
	printf("%d\n",countchar(str, c, 0));

}

//Implementation of a function to count the number of occureneces of character in a string recursively

int countchar(char *str,char c,int i){

	if(str[0] == c)
		return countchar(++str, c, ++i);
	
	else if (str[0] == '\0')
		return i;
	
	else 
		return countchar(++str, c, i);
}