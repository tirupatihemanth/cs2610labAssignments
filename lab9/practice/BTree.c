
#include "BTree.h"



Node *node_new(int data, Node *left ,Node *left){
	Node *node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->left = left;
	node->right = right;
	return node;
}

BTree *btree_new(){
	BTree *btree = (BTree *) malloc(sizeof(BTree));
	btree->root = NULL;
}

//As it is binary tree we can add the data at any point so it doesn't matter where we add
BTree *btree_add(BTree *btree, int data){

}

int btree_size(BTree *btree){
	Node *iterator = btree->root;
	return(size_calculate(iterator));
}

int size_calculate(Node *node){
	if(node == NULL)
		return 0;
	else
		return(size_calculate(node->left) + 1 + size_calculate(node->right));
}

int btree_max_depth(BTree *btree){
	Node *iterator = btree->root;
	return(max_depth_calculate(iterator));
}

int max_depth_calculate(Node *node){
	if(node == NULL)
		return 0;
	return max(max_depth_calculate(node->left)+1, max_depth_calculate(node->right)+1);
}

int max(int a, int b){
	return a>b?a:b
}

int btree_min(BTree *btree){
	Node *iterator = btree->root;
	return min_calculate(Node *iterator, btree->root->data);
}

int min_calculate(Node *node, int val){

	if(node == NULL)
		return val;
	int leftmin = min_calculate(node->left,node->data);
	int rightmin = min_calculate(node->right, node->data);

	return leftmin<rightmin?leftmin:rightmin;

}

int btree_haspathsum(BTree *btree){
	Node *iterator = btree->root;
	return haspathsum_calculate(iterator, sum);
}

int haspathsum_calculate(Node *node, int sum){

/*
	if(sum<0)
		return 0;
	if(sum == 0 && node->left == NULL && node->right == NULL){
		return 1;
	}
	else
		return 0;

	int left = haspathsum_calculate(node->left,sum-node->data);
	if(left == 1)
		return left;
	int right = haspathsum_calculate(node->right, sum-node->data);
	return right;
	*/

	//This is what is called optimisation check below which does same as above
	if(node == NULL)
		return sum == 0;
	return( haspathsum_calculate(node->left,sum-node->data) || haspathsum_calculate(node->right, sum-node->data) );

}

void btree_printpaths(BTree *btree){
	Node *iterator = btree->root;
	int paths[1000];
	printpaths(iterator, paths, 0);
}

void printpaths(Node *node, int paths[], pathLen){

	if(node == NULL)
		return;

	paths[pathLen] = node->data;
	pathLen++;

	if(node->left == NULL && node->right == NULL){
		printArray(paths, pathLen);
	}
	else{
		printpaths(node->left, paths, pathLen);
		printpaths(node->right, paths, pathLen);
	}

}

printArray(int paths[], pathLen){
	int i;
	for(i=0;i<pathLen;i++){
		printf("%d ",paths[i]);
	}
	printf("%d\n");
}

BTree *btree_mirror(BTree *btree){
	Node *iterator = btree->root;
    mirror_calculate(Node *iterator);
    return btree;
}

void mirror_calculate(Node *node){

	if(node == NULL)
		return;

	mirror_calculate(node->left);
	mirror_calculate(node->right);
	Node *temp = node->left;
	node->left = node->right;
	node->right = temp;

}

int btree_sametree(BTree *btree1, BTree *btree2){

	return sametree_check(btree1->root, btree2->root);

}

int sametree_check(Node *node1, Node *node2){

	if(node1 == NULL && node2 == NULL)
		return 1;
	else if(node1 != NULL && node2 !=NULL){

		return sametree_check(node1->left, node2->left) && sametree_check(node2->right, node2->right) && (node1->data == node2->data);

	}
	else
		return 0;

}