#ifndef LLIST_H
#define LLIST_H


typedef struct _Node Node;
struct _Node{
    int data;
    Node* next;
};

typedef struct _LList {
    Node* head;
    // int size; //Optional!
} LList;

// Creates a new node with data and next element
Node* node_new(int data, Node* next);

// Creates an empty list with head as null 
LList* llist_new();

// Traverse the linked list and return the size
int llist_size(LList* lst);

// Traverse the linked list and print each element
void llist_print(LList* lst);

// Gets the "idx"th element of the list
int llist_get(LList* lst, int idx);

// Add a new element at the end of the list
LList* llist_append(LList* lst, int data);

// Adds a new element at the beginning of the list
LList* llist_prepend(LList* lst, int data);

// Adds a new element at the idx index
LList* llist_insert(LList* lst, int idx, int data);

// Remove an element from the end of the list
LList* llist_remove_last(LList* lst);

// Remove an element from the beginning of the list
LList* llist_remove_first(LList* lst);

// Remove an element from @idx position
LList* llist_remove(LList* lst, int idx);

#endif
