#include<stdio.h>
#include<malloc.h>

typedef int DataType;
#include"LinList.h"

int myListInsert(SLNode **head, int i, DataType x){
    SLNode *q, *p;
    p = *head;
    int j;
    if(i==0){
        q = (SLNode *)malloc(sizeof(SLNode));
        q->data = x;
        q->next = (*head)->next;
        *head = q;
        return 1;
    }else{
        j=1;
        while(p->next!=NULL&&j<i){
            p = p->next;
            j++;
        }
        if(j!=i){
            printf("插入元素位置参数错！");
            return 0;
        }
        q = (SLNode *)malloc(sizeof(SLNode));
        q->data = x;
        q->next = p->next;
        p->next = q;
        return 1;
    }
}

int myListDelete(SLNode **head, int i, DataType *x){
    SLNode *q, *p;
    p = *head;
    int j = 1;
    if(i==0){
        *head = (*head)->next;
        return 1;
    }else{
        while(p->next!=NULL&&p->next->next!=NULL&&j<i){
        p = p->next;
        j++;
        }
        if(j!=i){
            printf("删除元素位置参数错！");
            return 0;
        }
        q = p->next;
        *x = q->data;
        p->next = p->next->next;
        free(q);
        return 1;
        }
}

int main()
{
    int i, x;
    SLNode *head;
    ListInitiate(&head);
    for(i=0;i<20;++i){
        myListInsert(&head, i, i);
    }
    myListDelete(&head, 1, &x);
    printf("%d ", head->next->data);
    return 0;
}