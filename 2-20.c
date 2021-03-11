#include<stdio.h>
#include<malloc.h>

typedef int DataType;
#include"LinList.h"

void print(SLNode *head){
    int i, x;
    for(i=0;i<ListLength(head);++i){
        ListGet(head, i, &x);
        printf("%d ", x);
    }
}

void reverse(SLNode *head){
    SLNode *p, *q;
    p = head->next;
    head->next = NULL;
    while(p!=NULL){
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
}

int main()
{
    SLNode *head;
    ListInitiate(&head);
    int i;
    for(i=0;i<20;++i){
        ListInsert(head, i, i);
    }
    reverse(head);
    print(head);
    return 0;
}