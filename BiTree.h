typedef struct Node
{
    DataType data;
    struct Node *leftChild;
    struct Node *rightChild;
} BiTreeNode;

void Initiate(BiTreeNode **root)
{
    *root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    (*root)->leftChild = NULL;
    (*root)->rightChild = NULL;
}

void Destory(BiTreeNode **root)
{
    if((*root)!=NULL&&(*root)->leftChild!=NULL){
        Destory(&(*root)->leftChild);
    }
    if((*root)!=NULL&&(*root)->rightChild!=NULL){
        Destory(&(*root)->rightChild);
    }
}

BiTreeNode *InsertLeftNode(BiTreeNode *curr, DataType x)
{
    BiTreeNode *s, *t;
    if(curr==NULL){
        return NULL;
    }
    t = curr->leftChild;
    s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    s->data = x;
    s->leftChild = t;
    s->rightChild = NULL;
    curr->leftChild = s;
    return curr->leftChild;
}

BiTreeNode *InsertRightNode(BiTreeNode *curr, DataType x)
{
    BiTreeNode *s, *t;
    if(curr==NULL){
        return NULL;
    }
    t = curr->rightChild;
    s = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    s->data = x;
    s->rightChild = t;
    s->leftChild = NULL;
    curr->rightChild = s;
    return curr->rightChild;
}

BiTreeNode *DeleteLeftTree(BiTreeNode *curr)
{
    if(curr==NULL||curr->leftChild==NULL){
        return NULL;
    }
    Destory(&curr->leftChild);
    curr->leftChild = NULL;
    return curr;
}

BiTreeNode *DeleteRightTree(BiTreeNode *curr)
{
    if(curr==NULL||curr->rightChild==NULL){
        return NULL;
    }
    Destory(&curr->rightChild);
    curr->rightChild = NULL;
    return curr;
}

void Visit(DataType item, int *cnt)
{
    printf("%d  ", item);
    ++(*cnt);
}

void PreOrder(BiTreeNode *root, int *cnt, void Visit(DataType item, int *cnt))
{
    if(root!=NULL){
        Visit(root->data, cnt);
        PreOrder(root->leftChild, cnt, Visit);
        PreOrder(root->rightChild, cnt, Visit);
    }
}

//int NodeNum(BiTreeNode *root)
//{
//	if(root==NULL){
//		return 0;
//	}else{
//		return NodeNum(root->leftChild) + NodeNum(root->rightChild) + 1;
//	}
//}
