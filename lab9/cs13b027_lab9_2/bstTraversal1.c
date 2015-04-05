/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Given pre order traversal of a tree obtain the post order traversal of the tree by constructing the binary search tree
 */


#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

int main(){
	int n,i;
	scanf("%d",&n);
	int postorder[n];
	for(i=0;i<n;i++)
		scanf("%d",postorder+i);
	BSTree *bstree = bstree_new();
	for(i=0;i<n;i++){
		bstree_add(bstree, postorder[i]);
	}

	bstree_print_postorder(bstree);

}