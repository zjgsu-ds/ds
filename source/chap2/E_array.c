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
int subseq(struct data_container *s, struct data_container *t);

int main()
{
    int n, i;
    elemType x;
    struct data_container s, t;

    init(&s, 10);
    init(&t, 10);

    scanf("A序列为 ");

    i = 1;
    while (scanf("%d", &x) == 1)
        insert(&s, i++, x);

    scanf("B序列为 ");

    i = 1;
    while (scanf("%d", &x) == 1)
        insert(&t, i++, x);

    if (subseq(&s, &t))
        printf("是");

    /* 清空容器空间 */
    destroy(&s);
    destroy(&t);

    return 0;
}

int subseq(struct data_container *s, struct data_container *t)
{
    int i, j;
    int M = s->n;
    int N = t->n;

    for (i = 0; i <= M - N; i++) {
        for (j = 0; j < N; j++)
            if (s->pData[i+j] != t->pData[j])
                break;

        if (j == N)
            return 1;
    }

    return 0;
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

