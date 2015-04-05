/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Binary Search Tree data structure (Implementation)
 *
 */

#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Implementation of a function to create new node

void print_sort(Node *);
void print_postorder(Node *);
int isbstree_evaluate(Node *, int ,int);
void doubletree_calculate(Node *);
int minvalue_evaluate(Node *);
int maxvalue_evaluate(Node *);
void delete_recursive(Node *);


Node* node_new(int data, Node* left, Node* right){

	Node *newnode = (Node *) malloc(sizeof(Node));
	newnode->data = data;
	newnode->left = left;
	newnode->right = right;

}

//Implementation of a function to delete a node

void node_delete(Node* node){
	free(node);
}

//Implementation of a function to delete the Binary Search Tree

void bstree_delete(BSTree *bstree){
	delete_recursive(bstree->root);
}

void delete_recursive(Node *node){
	if(node == NULL)
		return;
	delete_recursive(node->left);
	delete_recursive(node->right);
	free(node);
}
//Implementation of a function to create a new binary tree

BSTree* bstree_new(){

	BSTree *bstree = (BSTree *) malloc(sizeof(BSTree));
	bstree->root = NULL;

}

//Implementation to add an element to a binary search tree 

BSTree* bstree_add(BSTree *bstree, int data){

	Node *newnode = node_new(data, NULL, NULL);
	Node *iterator = bstree->root;

	if(bstree->root == NULL){
		bstree->root = newnode;
		return bstree;
	}

	while(1){

		if(iterator->data>data){

			if(iterator->left == NULL){
				iterator->left = newnode;
				break;
			}
			else
				iterator = iterator->left;

		}
		else if(iterator->data<data){

			if(iterator->right == NULL){
				iterator->right = newnode;
				break;
			}
			else
				iterator = iterator->right;

		}

	}

	return bstree;

}

//Implementation of a function to search a binary  search tree returns 1 if an element is present in the binary tree else returns 0

int bstree_search(BSTree *bstree, int data){

	Node *iterator = bstree->root;

	while(1){

		if(iterator == NULL)
			return 0;
		else if(iterator->data < data){
			iterator = iterator->right;
			continue;
		}
		else if(iterator->data > data){
			iterator = iterator->left;
			continue;
		}
		else if(iterator->data == data){
			return 1;
		}

	}

}

//Implementation of a function to delete a node in binary tree

BSTree *bstree_remove(BSTree *bstree, int data){

	Node *iterator = bstree->root , *temp, *temp1, *temp2;
	int newdata;
	if(iterator->data == data){
		temp = iterator;
		if((iterator = iterator->left) != NULL){
			if(iterator->right == NULL){
				iterator->right = temp->right;
				free(bstree->root);
				bstree->root = iterator;
				return bstree;
			}
			while(1){

				if(iterator->right->right == NULL){
					temp->data = iterator->right->data;
					temp2 = iterator->right->left;
					free(iterator->right);
					iterator->right = temp2;
					return bstree;
				}
				else
					iterator = iterator->right;
			}
		}
		else if((iterator = temp->right) != NULL){
				if(iterator->left == NULL){
					iterator->left = temp->left;
					free(bstree->root);
					bstree->root = iterator;
					return bstree;
				}
			while(1){
				if(iterator->left->left == NULL){
					temp->data = iterator->left->data;
					temp2 = iterator->left->right;
					free(iterator->left);
					iterator->left = temp2;
					return bstree;
				}
				else
					iterator = iterator->left;
			}
		}
		else{
			free(bstree->root);
			bstree->root = NULL;
			return bstree;
		}
	}

	while(1){
		if(iterator->data>data){
			temp1 = iterator;
			iterator = iterator->left;
			if(iterator->data == data){
				temp = iterator;
				if((iterator = iterator->left) != NULL){

					if(iterator->right == NULL){
						iterator->right = temp->right;
						free(temp1->left);
						temp1->left = iterator;
						return bstree;
					}
					while(1){
						if(iterator->right->right == NULL){
							newdata = iterator->right->data;
							temp2 = iterator->right->left;
							free(iterator->right);
							iterator->right = temp2;
							temp1->left->data = newdata;
							return bstree;
						}
						else
							iterator = iterator->right;
					}
				}
				else if((iterator = temp->right) != NULL){

						if(iterator->left == NULL){
							iterator->left = temp->left;
							free(temp1->left);
							temp1->left = iterator;
							return bstree;
						}
					while(1){
						if(iterator->left->left == NULL){
							newdata = iterator->left->data;
							temp2 = iterator->left->right;
							free(iterator->left);
							iterator->left = temp2;
							temp1->left->data = newdata;
							return bstree;
						}
						else
							iterator = iterator->left;
					}
				}
				else{
					free(temp1->left);
					temp1->left = NULL;
					return bstree;
				}
			}
			else
				continue;
		}
		if(iterator->data<data){
			temp1 = iterator;
			iterator = iterator->right;
			if(iterator->data == data){
				temp = iterator;
				if((iterator = iterator->left) != NULL){
						if(iterator->right == NULL){
							iterator->right = temp->right;
							free(temp1->right);
							temp1->right = iterator;
							return bstree;
						}
					while(1){
						if(iterator->right->right == NULL){
							newdata = iterator->right->data;
							temp2 = iterator->right->left;
							free(iterator->right);
							iterator->right = temp2;
							temp1->right->data = newdata;
							return bstree;
						}
						else
							iterator = iterator->right;
					}
				}
				else if((iterator = temp->right) != NULL){
					if(iterator->left == NULL){
						iterator->left = temp->left;
						free(temp1->right);
						temp1->right = iterator;
						return bstree;
					}
					while(1){
						if(iterator->left->left == NULL){
							newdata = iterator->left->data;
							temp2 = iterator->left->right;
							free(iterator->left);
							iterator->left = temp2;
							temp1->right->data = newdata;
							return bstree;
						}
						else
							iterator = iterator->left;
					}
				}
				else{
					free(temp1->right);
					temp1->right = NULL;
					return bstree;
				}
			}
			else 
				continue;

		}

	}

}

// Implementation of a function to print all the elements of binary search tree in breadth first order

void bstree_print_breadthfirst(BSTree *bstree){

	Node *node;
	int size = bstree_size(bstree);
	int array[size], i = 0, n = 0, data;
	array[n++] = bstree->root->data;
	while(1){
		data = array[i++];
		//printf("blah");
		node = bstree->root;
		while(1){
			if(node->data>data){
				node = node->left;
				continue;
			}
			else if(node->data<data){
				node = node->right;
				continue;
			}
			else{
				printf("%d ", node->data);
				if(node->left!=NULL)
					array[n++] = node->left->data;
				if(node->right != NULL)
					array[n++] = node->right->data;
				break;
			}
		}
		if(i==n)
			break;
	}

	printf("\n");
}

int bstree_size(BSTree *bstree){
	Node *iterator = bstree->root;
	return(size_calculate(iterator));
}

int size_calculate(Node *node){
	if(node == NULL)
		return 0;
	else
		return(size_calculate(node->left) + 1 + size_calculate(node->right));
}

//Implementation of a function to print all the elements of a binary search tree in sorted order
//printing in sorted order of a binary search tree is same as in order traversal

void bstree_print_sort(BSTree *bstree){
	Node *iterator = bstree->root;
	print_sort(iterator);
	printf("\n");
}

//Helper function for bstree_print_sort which prints the elements of a bstree in sorted order

void print_sort(Node *iterator){

	if(iterator == NULL)
		return;
	print_sort(iterator->left);
	printf("%d ",iterator->data);
	print_sort(iterator->right);

}

//Implementation of function to print the given tree in post order format

void bstree_print_postorder(BSTree *bstree){
	Node *iterator = bstree->root;
	print_postorder(iterator);
}

//private helper function for the bstree_print_postorder function

void print_postorder(Node *node){

	if(node == NULL)
		return;
	print_postorder(node->left);
	print_postorder(node->right);
	printf("%d ",node->data);
	
}

//Implementation of a function to return the double tree for the given binary search tree

BSTree *bstree_doubletree(BSTree *bstree){

	Node *iterator = bstree->root;
	doubletree_calculate(iterator);
	return bstree;
}

//Private helper function for the bstree_doubletree

void doubletree_calculate(Node *node){

	if(node == NULL)
		return;	

	doubletree_calculate(node->left);
	doubletree_calculate(node->right);

	Node *newnode = node_new(node->data,node->left,NULL);
	node->left = newnode;	
}

// Given num_nodes which is numbers from 1 to N(say) then countTrees will give number of structurally distinct binary search trees possible

int countTrees(int num_nodes){

	if(num_nodes<=1)
		return 1;

	int i,left,right,sum = 0;

	for(i=1;i<num_nodes;i++){
		
		left = countTrees(i-1);
		right = countTrees(num_nodes-i);

		sum += left*right;

	}
	return sum;

}

//given a binary search tree it returns the maximum value in the tree

int bstree_maxvalue(BSTree *bstree){

	return maxvalue_evaluate(bstree->root);
}

//This function serves two purposes one as a helper function to bstree_maxvalue (not that great) and the other is this function given any node can check the max in the subtree of the node

int maxvalue_evaluate(Node *node){

	if(node == NULL)
		return INT_MIN;

	while(node->right != NULL){
		node = node->right;
	}
	return node->data;

}

//given a binary search tree it returns the minimum value in the binary search tree

int bstree_minvalue(BSTree *bstree){

	return minvalue_evaluate(bstree->root);

}

//serves as both helper function for the bstree_minvalue and also can give the minvalue in the subtree given a node

int minvalue_evaluate(Node *node){

	if(node == NULL)
		return INT_MAX;

	while(node->left != NULL)
		node = node->left;
	return node->data;

}

//Given a binary tree it checks whether given binary is a binary search tree or not

int isbstree(BSTree *bstree){

	return isbstree_evaluate(bstree->root, INT_MIN, INT_MAX);

}

//Helper function for isbree function

int isbstree_evaluate(Node *node, int min, int max){

	if(node == NULL)
		return 1;
	if(node->data < INT_MIN || node->data > INT_MAX)
		return 0;
	return isbstree_evaluate(node->left, min, node->data) && isbstree_evaluate(node->right, node->data+1, max);

}
