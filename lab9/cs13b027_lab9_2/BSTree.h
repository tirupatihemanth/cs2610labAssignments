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

Node *node_new(int, Node *, Node *);

void node_delete(Node *);

void bstree_delete(BSTree *);

BSTree *bstree_new();

BSTree *bstree_add(BSTree *, int);

int bstree_search(BSTree *, int);

BSTree *bstree_remove(BSTree *, int);

void bstree_print_breadthfirst(BSTree *);

void bstree_print_sort(BSTree *);

void bstree_print_postorder(BSTree *);

int bstree_maxvalue(BSTree *);

int bstree_minvalue(BSTree *);

BSTree *bstree_doubletree(BSTree *);

int countTrees(int );

int isbstree(BSTree *);

#endif // BST_H

