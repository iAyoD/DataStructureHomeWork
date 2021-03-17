#include "SeqList.h"
void main() {
	SeqList myList;
	int i, x;

	ListInitiate(&myList);
	for ( i = 0; i < 10; i++)
	{
		scanf("%d", &x);
		listInsert(&myList, x);
	}

	//查找元素为5的位置
	i = ListFind(myList, 5);
	printf("%d\n", i);
	ListDelete(&myList, i, &x);

	for ( i = 0; i < ListLength(myList); i++){
		ListGet(myList, i, &x);
		printf("%d\t", x);
	}
}