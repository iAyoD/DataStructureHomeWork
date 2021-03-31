#include "LinList.h"
#pragma warning(disable : 4996)
void main() {
	SLNode* head;
	int i, x ,flag, lenght;
	ListInitiate(&head);

	//定义一个打印所有元素的函数
	void print(SLNode *head);

	printf("请输入生成元素的个数:");
	scanf("%d",&lenght);
	for (i  = 0; i < lenght; i++){
		ListInsert(head, i, i + 1);
	}
	print(head);

	//求个数
	int num;
	num = ListLenght(head);
	printf("该链表有%d个元素！\n", num);
	print(head);
	

	//插入
	printf("你需要插入的元素:");
	scanf("%d", &x);
	printf("你需要插入的元素的位置:");
	scanf("%d", &i);
	flag = ListInsert(head, i-1 , x);
	if (flag){
		printf("插入成功!\n");
		print(head);
	}
	
	//删除
	printf("你需要删除的元素的位置:");
	scanf("%d", &i);
	flag = ListDelete(head, i-1, &x);
	if (flag) {
		printf("元素%d删除成功!\n",x);
		print(head);
	}

	////打印所有元素
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