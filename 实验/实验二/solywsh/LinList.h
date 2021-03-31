#pragma once
#include <stdio.h>
#include <malloc.h>
#define DataType int

typedef struct Node {
	DataType data;
	struct Node* next;
}SLNode;

//��ʼ��
void ListInitiate(SLNode** head) {
	*head = (SLNode*)malloc(sizeof(SLNode));
	(*head)->next = *head;
}

//�����
int ListLenght(SLNode* head) {
	SLNode* p = head;
	int size = 0;

	while (p->next!=head){
		p = p->next;
		size++;
	}
	return size;
}

//����
int ListInsert(SLNode* head, int i, DataType x) {
	SLNode* p, * q;
	int j;

	p = head;
	j = -1;
	while (p->next!=head && j< i-1){
		p = p->next;
		j++;
	}
	if (j != i - 1) {
		printf("����Ԫ�ص�λ�ò�������");
		return 0;
	}

	q = (SLNode*)malloc(sizeof(SLNode));
	q->data = x;

	q->next = p->next;
	p->next = q;
	return 1;
}


//ɾ��
int ListDelete(SLNode* head, int i, DataType* x) {
	SLNode* p, * s;
	int j;
	p = head;
	j = -1;
	while (p->next != head && p->next->next != head && j < i - 1) {
		p = p->next;
		j++;
	}
	if (j!=i-1){
		printf("ɾ��Ԫ��λ�ò�������");
		return 0;
	}

	s = p->next;
	*x = s->data;
	p->next = p->next->next;
	free(s);
	return 1;
}

//ȡ����Ԫ��
int ListGet(SLNode* head, int i, DataType* x) {
	SLNode* p;
	int j;
	p = head;
	j = -1;
	while (p->next != head && j<i){
		p = p->next;
		j++;
	}
	if (j != i) {
		printf("ȡԪ��λ�ò�������");
		return 0;
	}

	*x = p->data;
	return 1;
}


//����������
void Destroy(SLNode** head) {
	SLNode* p, * p1;

	p = *head;
	while (p != NULL) {
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}