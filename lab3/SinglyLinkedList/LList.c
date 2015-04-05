/*
 *  Author: Tirupati Hemanth Kumar
 *  Roll No.: cs13b027
 *  Linked List Datastructure implementation using Structure data type 
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "LList.h"

//Implementation of new node

Node* node_new(int data,Node* next){

	Node* newnode;
	newnode = (Node*) malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = next;
	return newnode;

}

//Implementation of creation of new empty LList

LList* llist_new(){

	LList* new_llist = (LList*)malloc(sizeof(LList));
	new_llist->head = NULL;
	return new_llist;

}

//Implementation of size of a linked LList

int llist_size(LList* lst){

	int size=1;
	if(lst == NULL)
		return 0;
	Node* iterator = lst->head;
	if(iterator==NULL)
		return 0;
	while(iterator->next!=NULL){
		size+=1;
		iterator = iterator->next;
	}
	return size;

}

//Implementation to print each element in a linked list

void llist_print(LList* lst){

	Node* iterator = lst->head;
	if(iterator == NULL)
		return;
	while(iterator->next!=NULL){
		printf("%d\t",iterator->data);
		iterator = iterator->next;
	}
	printf("%d\n",iterator->data);

}

//Implementation to get an element at the index idx of the LList

int llist_get(LList* lst , int idx){

	int size = llist_size(lst);
	if(idx>size-1 || idx <0){
		printf("INVALIDhi\n");
		exit(1);
	}
	int counter=0;
	Node* iterator = lst->head;
	while(iterator->next!=NULL){
		if(counter == idx)
			return iterator->data;
		counter++;
		iterator = iterator->next;
	}
	return iterator->data;

}

//Implementation to append a new item at the end of the Linked List

LList* llist_append(LList* lst,int data){

	Node* iterator = lst->head;
	if(iterator == NULL){
		lst->head = node_new(data,NULL);
		return lst;
	}
	while(iterator->next!=NULL){
		iterator = iterator->next;
	}
	iterator->next = node_new(data,NULL);
	return lst;

}

//Implementation to prepend a new item at the end of the Linked List

LList* llist_prepend(LList *lst,int data){
	
	Node* oldhead = lst->head;
	lst->head = node_new(data,oldhead);

}

//Implementation to insert an element at the index idx of the linked list

LList* llist_insert(LList *lst, int idx, int data){
	int size = llist_size(lst);
	if(idx>size-1 || idx <0){
		printf("INVALID\n");
		exit(1);
	}
	Node* iterator = lst->head;
	int i;
	if(idx==0)
		return llist_prepend(lst,data);
	for(i=0;i<idx-1;i++){
		iterator = iterator->next;
	}
	Node* suffix = iterator->next;
	iterator->next = node_new(data,suffix);
	return lst;

}

//Implementation to remove last element from the Linked List

LList* llist_remove_last(LList* lst){

	int size = llist_size(lst);
	if(size==0){
		printf("INVALID\n");
		exit(1);
	}
	if(size==1){
		free(lst->head);
		lst->head = NULL;
		return lst;
	}
	Node* iterator = lst->head;
	int i;
	for(i=0;i<size-2;i++){
		iterator = iterator->next;
	}
	free(iterator->next);
	iterator->next = NULL;
	return lst;
}

//Implementation to remove first element from a Linked List

LList* llist_remove_first(LList* lst){
	
	if(lst->head==NULL){
		printf("INVALID\n");
		exit(1);
	}
	Node* oldhead = lst->head;
	lst->head = oldhead->next;
	free(oldhead);

}

//Implementation to remove an element at an index in a Linked List

LList* llist_remove(LList* lst, int idx){

	int size = llist_size(lst);
	if(idx>size-1 || idx <0){
		printf("INVALID\n");
		exit(1);
	}
	Node* iterator = lst->head;
	int i;
	for(i=0;i<idx-1;i++){
		iterator = iterator->next;
	}
	Node* suffix = iterator->next;
	iterator->next = suffix->next;
	free(suffix);

}