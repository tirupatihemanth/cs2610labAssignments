#include <stdio.h>
#include "BSTree.h"

int main(){

	int n,i,data;
	scanf("%d",&n);
	BSTree *bstree = bstree_new();
	for(i=0;i<n;i++){
		scanf("%d",&data);
		bstree_add(bstree, data);
		//bstree_print_sort(bstree);
	}

	bstree_print_breadthfirst(bstree);
	return 0;
}