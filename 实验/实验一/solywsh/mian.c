#include "SeqList.h"
void main() {
	SeqList myList;
	int i, j, x, flag = 0;

	//插入
	ListInitiate(&myList);
	for ( i = 0; i < 10; i++)
	{
		printf("请输入第%d个数:", i + 1);
		scanf("%d", &x);
		listInsert(&myList, x);
	}

	//打印全部
	for (i = 0; i < ListLength(myList); i++) {
		ListGet(myList, i, &x);
		printf("%d ", x);
	}
	printf("\n");

	//查找删除
	printf("请输入需要删除的元素:");
	scanf("%d",&j);
	for (;!flag;){
		i = ListFind(myList, j);
		if (i != -1){
			printf("找到位置为%d!\n", i+1);
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