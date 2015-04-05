#include <stdio.h>
#include <stdlib.h>
#include "LList.h"

// Creates a new node with data and next element
Node* node_new(int data, Node* next) {
    Node* temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    temp->next = next;
    return temp;
}

// Creates an empty list with head as null 
LList* llist_new() {
    LList* lst = (LList *) malloc(sizeof(LList));
    lst->head = NULL;
    return lst;
}

void llist_delete(LList* lst) {
    free(lst);
}

LList* make_copy(LList* lst) {
    LList* lst2 = llist_new();
    Node* temp = lst->head;
    int count = 0;
    while(temp != NULL) {
        Node* new = node_new(temp->data, temp->next);
        if(count == 0) {
            lst2->head = new;
        }
        count++;
        temp = temp->next;
    }
    return lst2;
}

// Traverse the linked list and return the size
int llist_size(LList* lst) {
    int count = 0;
    if(lst == NULL) {
        return 0;
    }
    Node* temp = lst->head;
    while(temp != NULL) {
        count += 1;
        temp = temp->next;
    }
    return count;
}

// Traverse the linked list and print each element
void llist_print(LList* lst) {
    Node* temp = lst->head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }    
    printf("\n");
}

// Gets the "idx"th element of the list
int llist_get(LList* lst, int idx){
    int sz = llist_size(lst);
    if(idx >= sz || idx < 0) {
        printf("Index out of bounds\n");
        return -1;
    }
    Node* tmp = lst->head;
    while(idx--) {
        tmp = tmp->next;
    }
    return tmp->data;
}

// Add a new element at the end of the list
LList* llist_append(LList* lst, int data) {
    Node* tmp = lst->head;
    Node* elt = node_new(data, NULL);
    if(tmp == NULL) {
        lst->head = elt;
        return lst;
    }
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = elt;
    return lst;
}

// Adds a new element at the beginning of the list
LList* llist_prepend(LList* lst, int data){
    Node* tmp = lst->head;
    Node* elt = node_new(data, tmp);
    lst->head = elt;
    return lst;
}

// Adds a new element at the idx index
LList* llist_insert(LList* lst, int idx, int data){
    int sz = llist_size(lst); // Replace with lst->size
    if(idx > sz || idx < 0) {
        printf("Index out of bounds\n");
        return lst;
    }
    if(idx == 0) {
        return llist_prepend(lst, data);
    }
    else if(idx == sz) {
        return llist_append(lst, data);
    }
    else {
        Node* tmp = lst->head;
        Node* elt = node_new(data, NULL);
        while(--idx) {
            tmp = tmp->next;
        }
        elt->next = tmp->next;
        tmp->next = elt;
    }
    return lst;
}

// Remove an element from the end of the list
LList* llist_remove_last(LList* lst){
    int sz = llist_size(lst);
    if(sz == 0) {
        return lst;
    }
    else if(sz == 1) {
        return llist_remove_first(lst);
    }
    else {
        int idx = sz - 2;
        Node* tmp = lst->head;
        while(idx--) {
            tmp = tmp->next;
        }
        Node* to_delete = tmp->next;
        tmp->next = to_delete->next;
        free(to_delete);
        return lst;
    }
    
}

// Remove an element from the beginning of the list
LList* llist_remove_first(LList* lst) {
    Node* temp = lst->head;
    if(lst->head == NULL) {
        return lst;
    }
    lst->head = temp->next;
    free(temp);
    return lst;
}

// Remove an element from @idx position
LList* llist_remove(LList* lst, int idx) {
    int sz = llist_size(lst);
    if(idx >= sz || idx < 0) {
        printf("Index out of bounds\n");
        return lst;
    }
    if(idx == 0) {
        return llist_remove_first(lst);
    }
    else if(idx == sz - 1) {
        return llist_remove_last(lst);
    }
    else {
        Node* tmp = lst->head;
        while(--idx) {
            tmp = tmp->next;
        }
        Node* to_delete = tmp->next;
        tmp->next = to_delete->next;
        free(to_delete);
        //lst->size--;
        return lst;
    }
}
