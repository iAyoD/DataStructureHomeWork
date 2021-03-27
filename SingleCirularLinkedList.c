typedef struct Node{
    DataType data;
    struct Node *next;
}SCLNode;

void ListInitiate(SCLNode **head)
{
    *head = (SCLNode *)malloc(sizeof(SCLNode));
    (*head)->next = *head;
}

int ListLength(SCLNode *head){
    SCLNode *p = head;
    int size = 0;
    while(p->next!=head){
        p = p->next;
        size++;
    }
    return size;
}

int ListInsert(SCLNode *head, int i, DataType x){
    SCLNode *p, *q;
    int j;
    p = head;
    j=-1;
    while(p->next!=head&&j<i-1){
        p = p->next;
        j++;
    }
    if(j!=i-1){
        printf("插入元素位置参数错！");
        return 0;
    }
    q = (SCLNode *)malloc(sizeof(SCLNode));
    q->data = x;
    q->next = p->next;
    p->next = q;
    return 1;
}

int ListDelete(SCLNode *head, int i, DataType *x){
    SCLNode *p, *s;
    int j;
    p = head;
    j = -1;
    while(p->next!=head&&p->next->next!=head&&j<i-1){
        p = p->next;
        j++;
    }
    if(j!=i-1){
        printf("删除元素位置参数错！");
        return 0;
    }
    s = p->next;
    *x = s->data;
    p->next = p->next->next;
    free(s);
    return 1;
}

int ListGet(SCLNode *head, int i, DataType *x){
    SCLNode *p;
    int j;
    p = head;
    j = -1;
    while(p->next!=head&&j<i){
        p = p->next;
        j++;
    }
    if(j!=i){
        printf("取元素位置参数错！");
        return 0;
    }
    *x = p->data;
    return 1;
}