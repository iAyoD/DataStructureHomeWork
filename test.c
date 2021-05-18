#include<stdio.h>
#include<malloc.h>

typedef int DataType;
#include"BiTree.h"

int main()
{
	int cnt=0;
	BiTreeNode *myBitree, *curr;
	Initiate(&myBitree);
	curr = InsertLeftNode(myBitree, 1);
	InsertLeftNode(curr, 2);
	curr = InsertRightNode(curr, 3);
	InsertRightNode(curr, 5);
	curr = InsertLeftNode(curr, 4);
	InsertLeftNode(curr, 6);
	PreOrder(myBitree->leftChild, &cnt, Visit);
	printf("\nTotal nodes:\t%d", cnt);
	return 0;
}
