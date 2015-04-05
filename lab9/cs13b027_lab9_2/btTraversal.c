#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"


int *inorder;
int indexof(int);
void btree_print_sort(Node *);
int main(){

	int n,i;
	scanf("%d",&n);
	int postorder[n];
	inorder = (int *) malloc(sizeof(int)*n);

	for(i=0;i<n;i++){
		scanf("%d",inorder+i);
		//printf("%d",inorder[i]);
	}

	for(i=0;i<n;i++){
		scanf("%d",postorder+i);
	}
	BSTree *bstree = bstree_new();
	for(i = n-1;i>=0;i--){
		bstree_add(bstree,indexof(postorder[i]));
	}
	btree_print_sort(bstree->root);
	printf("\n");
	return 0;
}

int indexof(int data){
	int i=0;
	while(1){
		if(inorder[i] == data){
			//printf("blah\n");
			return i;
		}
		i++;
	}
}

void btree_print_sort(Node *node){
	if(node == NULL)
		return;

	printf("%d ",inorder[node->data]);
	node->data = inorder[node->data];
	btree_print_sort(node->left);
	btree_print_sort(node->right);
}