#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"
#include "QFS.h"
#include "SFQ.h"

/* Some tester code*/
int main() {

    
   
    QFS* q = qfs_new();
    q = qfs_enqueue(q, 5);
    q = qfs_enqueue(q, 6);
    q = qfs_enqueue(q, 7);
    q = qfs_enqueue(q, 8);
    int ret;
    q =qfs_dequeue(q, &ret);
    printf("%d\n", ret);
    q = qfs_enqueue(q, 9);
    
    q =qfs_dequeue(q, &ret);
    printf("%d\n", ret);
    q =qfs_dequeue(q, &ret);
    printf("%d\n", ret);
    q =qfs_dequeue(q, &ret);
    printf("%d\n", ret);
    q =qfs_dequeue(q, &ret);
    printf("%d\n", ret);
    
 
    SFQ* st = sfq_new();
    st = sfq_push(st, 5);
    
    st = sfq_push(st, 6);
    st = sfq_push(st, 7);
    st = sfq_push(st, 8);
    st = sfq_push(st, 9);
    int t;
    st = sfq_pop(st, &t);
    printf("%d\n", t);
    st = sfq_pop(st, &t);
    printf("%d\n", t);
    st = sfq_pop(st, &t);
    printf("%d\n", t);
    st = sfq_pop(st, &t);
    printf("%d\n", t);
    st = sfq_pop(st, &t);
    printf("%d\n", t);
    return 0;
}

