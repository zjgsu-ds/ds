#include <stdio.h>
#include <stdlib.h>

typedef int elemType;
struct data_container {
    elemType *pData;
    int size;
    int n;
} ;

void init(struct data_container *s, int size);
void destroy(struct data_container *s);
void insert(struct data_container *s, int i, elemType b);
void inverse(struct data_container *s);

int main()
{
    int n, i;
    elemType x;
    struct data_container s;

    init(&s, 10);

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&s, i+1, x);
    }

    inverse(&s);

    for (i = 0; i < s.n; i++)
        printf("%d ", s.pData[i]);

    /* 清空容器空间 */
    destroy(&s);

    return 0;
}

void inverse(struct data_container* s)
{
    int i = 0;
    int j = s->n - 1;
    int tmp;

    while (i < j) {
        tmp = s->pData[i];
        s->pData[i] = s->pData[j];
        s->pData[j] = tmp;
        i++;
        j--;
    }
}

/* 初始化数据容器的存储空间 */
void init(struct data_container *s, int size)
{
    s->pData = (elemType*)malloc(sizeof(elemType) * size);
    s->size = size;
    s->n = 0;
}

/* 清空数据容器的存储空间 */
void destroy(struct data_container *s)
{
    free(s->pData);
    s->size = 0;
    s->n = 0;
}

/* 在第i个位置插入一个数b */
void insert(struct data_container *s, int i, elemType b)
{
    int j = 0;

    if(s->n == s->size) { /* 容器空间不足 */
        // 为容器申请新的更大空间
        elemType *pNewData = (elemType*) malloc ( sizeof(elemType) * 2*s->size);

        // 把原空间中数据移到新空间中
        for(j = 0; j < s->n; j ++) {
            pNewData[j] = s->pData[j];
        }

        // 用新空间替换旧空间
        free(s->pData);
        s->pData = pNewData;
        s->size = 2*s->size;
    }

    // 插入数b
    for(j = s->n-1; j >= (i-1); j --) {
        s->pData[j+1] = s->pData[j];
    }

    s->pData[i-1] = b;
    s->n ++;
}

