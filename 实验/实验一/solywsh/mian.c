#include "SeqList.h"
void main() {
	SeqList myList;
	int i, j, x, flag = 0;

	//����
	ListInitiate(&myList);
	for ( i = 0; i < 10; i++)
	{
		printf("�������%d����:", i + 1);
		scanf("%d", &x);
		listInsert(&myList, x);
	}

	//��ӡȫ��
	for (i = 0; i < ListLength(myList); i++) {
		ListGet(myList, i, &x);
		printf("%d ", x);
	}
	printf("\n");

	//����ɾ��
	printf("��������Ҫɾ����Ԫ��:");
	scanf("%d",&j);
	for (;!flag;){
		i = ListFind(myList, j);
		if (i != -1){
			printf("�ҵ�λ��Ϊ%d!\n", i+1);
			ListDelete(&myList, i, &x);
		}
		else{
			flag = 1;
		}
	}

	for ( i = 0; i < ListLength(myList); i++){
		ListGet(myList, i, &x);
		printf("%d ", x);
	}
}