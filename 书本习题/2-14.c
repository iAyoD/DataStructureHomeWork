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

int main()
{
    SeqList L;
    ListInitiate(&L);
    int i;
    for(i=0;i<20;++i){
        ListInsert(&L, i, i);
    }
    print(L);
    return 0;
}