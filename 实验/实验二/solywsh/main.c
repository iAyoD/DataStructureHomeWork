#include "LinList.h"
#pragma warning(disable : 4996)
void main() {
	SLNode* head;
	int i, x ,flag, lenght;
	ListInitiate(&head);

	//����һ����ӡ����Ԫ�صĺ���
	void print(SLNode *head);

	printf("����������Ԫ�صĸ���:");
	scanf("%d",&lenght);
	for (i  = 0; i < lenght; i++){
		ListInsert(head, i, i + 1);
	}
	print(head);

	//�����
	int num;
	num = ListLenght(head);
	printf("��������%d��Ԫ�أ�\n", num);
	print(head);
	

	//����
	printf("����Ҫ�����Ԫ��:");
	scanf("%d", &x);
	printf("����Ҫ�����Ԫ�ص�λ��:");
	scanf("%d", &i);
	flag = ListInsert(head, i-1 , x);
	if (flag){
		printf("����ɹ�!\n");
		print(head);
	}
	
	//ɾ��
	printf("����Ҫɾ����Ԫ�ص�λ��:");
	scanf("%d", &i);
	flag = ListDelete(head, i-1, &x);
	if (flag) {
		printf("Ԫ��%dɾ���ɹ�!\n",x);
		print(head);
	}

	////��ӡ����Ԫ��
	//for ( i = 0; i < ListLenght(&head); i++){
	//	ListGet(&head, i, &x);
	//	printf("%d ", x);
	//}

}


void print(SLNode *head) {
	int i,x;
	for (i = 0; i < ListLenght(head); i++) {
		ListGet(head, i, &x);
		printf("%d ", x);
	}
	printf("\n");
}