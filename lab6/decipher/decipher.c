/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * program to decipher the code using recursive algorithm
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decrypt(char *, int, int);
void swap(char *, char *);
char enem_ger[5][8] = {"poland","austria","russia","france","england"};

//Implementation of the main function which calls decrypt function for decrypt function for decryption

void main(){
	int i =0;
	char encrypted[7];
	scanf("%s",encrypted);
	//printf("%d\n",strlen(encrypted));
	if(strlen(encrypted)>6){
		printf("hoax\n");
		return;
	}
	char addon[9], drops[][2] = {"a","t","s","n","l"};
	for(i=0;i<=4;i++){
		strcpy(addon,encrypted);
		strcat(addon,drops[i]);
		decrypt(addon,0,strlen(addon)-1);
	}
	printf("hoax\n");
} 

//Implementation of a function to decrypt the given message using an algorithm to first find all the permutations possible and then adding letter accordingly

void decrypt(char *ptr, int left, int right){
	int i,j;
	if(left == right){
		//printf("%s\n",ptr);
		for(j=0;j<=4;j++){
			if(strcmp(enem_ger[j],ptr) == 0){
				printf("%s\n",ptr);
				exit(0);
			}
		}
	}
	else{
		for(i = left ;i <= right;i++){
			swap(ptr+left,ptr+i);
			decrypt(ptr, left+1, right);
			swap(ptr+left, ptr+i);
		}
	}
}

//Implementation of the private function which helps in swapping elements in decrypt function which is just permutation of strings

void swap(char *ptr1, char *ptr2){
	char temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
