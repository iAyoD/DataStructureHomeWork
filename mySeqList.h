typedef struct{
    DataType list[MaxSize];
    int size;
}mySeqList;

void initiate(mySeqList *L){
    L->size = 0;
}

int list_insert(mySeqList *L, DataType x){
    int i, j, flag = 0;
    if(L->size >=MaxSize){
        printf("顺序表已满无法插入！\n");
        return 0;
    }else{
        for(int i=0;i<L->size;++i){
            if(x<L->list[i]){
                flag = 1;
                j = i;
                break;
            }
        }
        if(!flag){
            L->list[L->size] = x;
        }else{
            for(int i=L->size;i>j;--i){
                L->list[i] = L->list[i-1];
            }
            L->list[j] = x;
        }
        ++(L->size);
        return 1;
    }
}

int search_delete(mySeqList *L, DataType x){
    int i, j, isExist=0, cnt = 0;
    if(L->size<=0){
        printf("顺序表已空无数据元素可删！\n");
        return 0;
    }else{
        for(i=0;i<L->size;++i){
            if(x==L->list[i]){
                isExist = 1;
            }
            if(isExist){
                for(j=i;j<L->size;++j){
                    L->list[j] = L->list[j+1];
                }
                ++cnt;
                isExist = 0;
                --i;
            }
        }
        while(cnt--){
            --(L->size);
        }
        return 1;
    }
    if(!isExist){
        printf("未找到该元素！\n");
        return 0;
    }
}

void print_all(mySeqList L){
    int i;
    for(i=0;i<L.size;++i){
        printf("%d ", L.list[i]);
    }
}