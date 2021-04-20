void Visit(DataType item)
{
    printf("%c  ", item);
}

void PreOrder(BiTreeNode *root, void Visit(DataType item))
{
    if(root!=NULL){
        Visit(root->data);
        PreOrder(root->leftChild, Visit);
        PreOrder(root->rightChild, Visit);
    }
}

void InOrder(BiTreeNode *root, void Visit(DataType item))
{
    if(root!=NULL){
        PreOrder(root->leftChild, Visit);
        Visit(root->data);
        PreOrder(root->rightChild, Visit);
    }
}

void PostOrder(BiTreeNode *root, void Visit(DataType item))
{
    if(root!=NULL){
        PreOrder(root->leftChild, Visit);
        PreOrder(root->rightChild, Visit);
        Visit(root->data);
    }
}