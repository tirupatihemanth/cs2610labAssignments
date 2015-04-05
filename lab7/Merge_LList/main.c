/*
 * Author: <Name> | 
 * 
 */

#include "LList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*
 * The template code given here is for reference only
 * You are free to implement the functions in any way you want
 * You can change the parameter types, return values, add or remove functions
 */
// Function to merge two sorted lists
// Input: head of 1st sorted list, head of 2nd sorted list
// Output: head of the combined sorted list
/*
Node* merge(Node* head1, Node* head2) {
	
}
*/
// This function splits the given list into two.
// Input: head: head of input list
// head1 would then have the head of the first half of list
// head2 will have the head of the second half of the list.
/*
void split_list(Node* head, Node** head1, Node** head2) {
    
}
*/
// Input: head of the unsorted list
// Output: head of the sorted list

/*Node* merge_sort_internal(Node* head) {
    
}
*/

//merge function which implements the merging of two subsets in the same set without using extra nodes i.e rearranges there itself

void merge(LList* head, int left1, int right1,int left2, int right2){
	LList *lst = llist_new();
	int i = left1;
	int j = left2;
	int k=0;	
	while(1){
		if( i > right1 && j > right2)
			break;
		if(i<=right1 && j<=right2){
			if(llist_get(head,i)<=llist_get(head,j)){
				llist_append(lst, llist_get(head,i));
				i++;
				continue;
			}
			else{
				llist_append(lst, llist_get(head,j));
				j++;
				continue;
			}
		}
		else{
			if(i<=right1){
				llist_append(lst, llist_get(head,i));
				i++;
				continue;			
			}
			else if(j<=right2){
				llist_append(lst, llist_get(head,j));
				j++;
				continue;
			}	
		}
		
	}
	
	for(i=left1;i<=right1;i++){
		llist_remove(head,i);
		llist_insert(head,i,llist_get(lst,k));
		k++;		
	}
	for(i=left2;i<=right2;i++){
		llist_remove(head,i);
		llist_insert(head,i,llist_get(lst,k));
		k++;		
	}
	llist_delete(lst);	
}

//Sort function which implements the code recursively

void merge_sort(LList* lst, int left, int right) {

	int i;
	if(left == right)
		return;
	if(right - left >0){

		merge_sort(lst,left,(left+right)/2);
		merge_sort(lst,((left+right)/2)+1,right);
		merge(lst, left, (left+right)/2, ((left+right)/2)+1, right);
	}
	
}

int main() {
    LList* lst = llist_new();
    int i = 0;
    struct timeval t1;
    gettimeofday(&t1, NULL);
    srand(t1.tv_usec * t1.tv_sec);
    for(i = rand()%100; i > 0; i--) {
        llist_append(lst, rand()%1000);
    }
    
    printf("Given list is: \n");
    llist_print(lst);
    printf("Sorted list is: \n");
    merge_sort(lst,0,(llist_size(lst)-1));
    llist_print(lst);

}
