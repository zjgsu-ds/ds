
#include <stdio.h>
#include <stdlib.h>

const int maxLen = 100;
typedef float elemType;
struct data_container
{
    elemType *pData;
    int size;
    int n;
} ;

void init(struct data_container *s, int size);
void destroy(struct data_container *s);
void insert(struct data_container *s, int i, elemType b);
void del(struct data_container *s, int i);
int search(struct data_container *s, elemType b);

int main()
{
    int i, j;
    elemType b;

    // 一个浮点数据存储空间容器
    struct data_container s;

    // 初始化容器空间
    init(&s, maxLen);

    // 在第i个位置前插入一个数b
    i = 1;
    b = 3.6;
    insert(&s, i, b);

    // 删除第i个整数
    i = 1;
    del(&s, i);

    // 查找数 b
    b = 2.2;
    j = search(&s, b);

    if(j < 0){
        printf("no found of %f\n", b);
    }
    else{
        printf("found of %f\n", b);
    }

    // 清空容器空间
    destroy(&s);

    return 0;
}

void init(struct data_container *s, int size)
{
    // 初始化数据容器的存储空间
    s->pData = (elemType*)malloc(sizeof(elemType) * size);
    s->size = size;
    s->n = 0;
}

void destroy(struct data_container *s)
{
    // 清空数据容器的存储空间
    free(s->pData);
    s->size = 0;
    s->n = 0;
}

void insert(struct data_container *s, int i, elemType b)
{
    // 在第i个位置前插入一个数b
    int j = 0;

    if(s->n == s->size){ // 容器空间不足
        // 为容器申请新的更大空间
        elemType *pNewData = (elemType*) malloc ( sizeof(elemType) * 2*s->size);

        // 把原空间中数据移到新空间中
        for(j = 0; j < s->n; j ++){
            pNewData[j] = s->pData[j];
        }

        // 用新空间替换旧空间
        free(s->pData);
        s->pData = pNewData;
        s->size = 2*s->size;
    }

    // 插入数b
    for(j = s->n-1; j >= (i-1); j --)
    {
        s->pData[j+1] = s->pData[j];
    }

    s->pData[i-1] = b;
    s->n ++;
}

void del(struct data_container *s, int i)
{
    // 删除第i个整数
    int j = 0;

    for(j = i; j <= s->n-1; j ++)
    {
        s->pData[j-1] = s->pData[j];
    }

    s->n --;
}

int search(struct data_container *s, elemType b)
{
    // 查找整数 b
    int j = 0;

    for(j = 0; j <= s->n-1; j ++)
    {
        if(b == s->pData[j])
            break;
    }

    return (j >= s->n ? -1: j+1);
}
