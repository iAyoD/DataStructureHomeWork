#pragma once
#include <malloc.h>
#include <stdio.h>
#define MaxSize 100
typedef int DataType;

typedef struct {
    DataType list[MaxSize];
    int size;
}SeqList;

void ListInitiate(SeqList* L) {
    L->size = 0;
}

int ListLength(SeqList L) {
    return L.size;
}
//���뵽λ��i
//int ListInsert(SeqList* L, int i, DataType x) {
//    int j;
//    if (L->size >= MaxSize) {
//        printf("˳��������޷����룡\n");
//        return 0;
//    }
//    else if (i < 0 || i > L->size) {
//        printf("����i���Ϸ���\n");
//        return 0;
//    }
//    else {
//        for (j = L->size; j > i; j--) {
//            L->list[j] = L->list[j - 1];
//        }
//        L->list[i] = x;
//        L->size++;
//        return 1;
//    }
//}


//˳�����
int listInsert(SeqList* L, DataType x) {
    int i, j, flag = 0;
    if (L->size >= MaxSize) {
        printf("˳��������޷����룡\n");
        return 0;
    }
    else {
        for (int i = 0; i < L->size; ++i) {
            if (x < L->list[i]) {
                flag = 1;
                j = i;
                break;
            }
        }
        if (!flag) {
            L->list[L->size] = x;
        }
        else {
            for (int i = L->size; i > j; --i) {
                L->list[i] = L->list[i - 1];
            }
            L->list[j] = x;
        }
        ++(L->size);
        return 1;
    }
}

int ListDelete(SeqList* L, int i, DataType* x) {
    int j;
    if (L->size <= 0) {
        printf("˳����ѿ�������Ԫ�ؿ�ɾ��\n");
        return 0;
    }
    else if (i < 0 || i > L->size - 1) {
        printf("����i���Ϸ���\n");
        return 0;
    }
    else {
        *x = L->list[i];
        for (j = i + 1; j <= L->size - 1; j++) {
            L->list[j - 1] = L->list[j];
        }
        L->size--;
        return 1;
    }
}

int ListFind(SeqList L, DataType x) {
    
    for (int i = 0; i < ListLength(L); i++)
    {
        if (x == L.list[i]){
            return i;
        }
    }
    return -1;
}


int ListGet(SeqList L, int i, DataType* x) {
    if (i<0 || i>L.size - 1) {
        printf("����i���Ϸ���\n");
        return 0;
    }
    else {
        *x = L.list[i];
        return 1;
    }
}