#ifndef BTREE_H
#define BTREE_H

typedef Struct Node_{
	int data;
	Node *left;
	Node *right;
} Node;

typedef Struch BTree_ {
	Node *root;
} BTree;



#endif