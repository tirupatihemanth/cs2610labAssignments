/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Token System
 */
#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] )
{
  // TODO: Read a stream of integers using scanf. Stop when you see a
  //       -1
  // TODO: For each token - check if the token exists in the
  //       collection. If no - add to the collection. If yes - remove.
  // TODO: Print when done

	int token;
	BSTree *bstree = bstree_new();
	while(1){

		scanf("%d",&token);
		if(token!=EOF){
			//printf("search result %d\n", bstree_search(bstree, token));
			if(!bstree_search(bstree, token))
				bstree_add(bstree, token);
			else
				bstree_remove(bstree, token);
		}
		else
			break;
		bstree_print_sort(bstree);
	}
	printf("blah\n");
	bstree_print_breadthfirst(bstree);
	printf("\n");
	bstree_delete(bstree);
  return 0;
}

