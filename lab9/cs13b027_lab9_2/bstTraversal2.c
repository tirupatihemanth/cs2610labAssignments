/*
 * Name: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Given pre order traversal of a bstree obtain the post order traversal of the bstree without constructing the binary search tree
 */



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_postorder(int, int);

int *preorder,n;

int main(){

	int i;
	scanf("%d",&n);
	preorder = (int *) malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",preorder+i);
	}
	print_postorder(INT_MIN,INT_MAX);
	return 0;
}


void print_postorder(int min, int max){
	int i;
	for(i=0;i<n;i++){
		if(preorder[i]>min && preorder[i]<max){
			break;
		}
		else if(i == n-1)
			return;
	}
	print_postorder(min,preorder[i]);
	print_postorder(preorder[i],max);
	printf("%d ",preorder[i]);
}