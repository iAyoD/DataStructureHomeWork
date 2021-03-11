#include<stdio.h>

typedef int DataType;
#define MaxSize 100
#include"SeqList.h"

void print(SeqList L){
    int i, x;
    for(i=0;i<ListLength(L);++i){
        ListGet(L, i, &x);
        printf("%d ", x);
    }
}

void reverse(SeqList *L){
    int i, j, t;
    for(i=0, j=ListLength(*L)-1;i<ListLength(*L)/2;++i, --j){
        t = L->list[i];
        L->list[i] = L->list[j];
        L->list[j] = t;
    }
}

int main()
{
    SeqList L;
    ListInitiate(&L);
    int i;
    for(i=0;i<20;++i){
        ListInsert(&L, i, i);
    }
    reverse(&L);
    print(L);
    return 0;
}