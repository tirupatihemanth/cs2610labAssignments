/*
 * Author: Tirupati Hemanth Kumar
 * Roll No.: cs13b027
 * Binary Search Tree data structure
 *
 */

#ifndef BST_H
#define BST_H

// Node for the link list
typedef struct Node_ Node;
struct Node_ {
    int data;
    Node* left;
    Node* right;
};

// Link list structure
typedef struct BSTree_ {
    Node* root;
} BSTree;

// TODO: Write functions to add/remove an element from the binary tree. 
// TODO: Write a function to search if an element belongs to the BST
// TODO: Write a function to print out the whole BST

//To create a new node

Node *node_new(int, Node *, Node *);

//To delete a node

void node_delete(Node *);

//To delete the entire binary search tree

void bstree_delete(BSTree *);

//Creates a new binary tree and set's the root to NULL

BSTree *bstree_new();

//Add an element to the binary tree

BSTree *bstree_add(BSTree *, int);

//Search for an element in the binary tree

int bstree_search(BSTree *, int);

//removes an element from the binary tree 

BSTree *bstree_remove(BSTree *, int);

//prints the binary search tree in the breadth first traversal form

void bstree_print_breadthfirst(BSTree *);

//prints the binary search tree in the sorted or inorder form

void bstree_print_sort(BSTree *);

//prints the binary search tree in the post order tree traversal format

void bstree_print_postorder(BSTree *);

//Given a binary search tree prints the maximum value of the data found in the tree

int bstree_maxvalue(BSTree *);

//Given a binary search tree returns the minimum value of the data found in the tree

int bstree_minvalue(BSTree *);

//Given a binary search tree returns the binary double search tree

BSTree *bstree_doubletree(BSTree *);

//Given a number n returns the no. of binary search trees that can be formed using numbers from 1 to n

int countTrees(int );

//Given a binary tree returns whether it is binary search tree or not 

int isbstree(BSTree *);

#endif // BST_H

