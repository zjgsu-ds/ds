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
void merge(struct data_container *s, struct data_container *t, struct data_container *res);

int main()
{
    int n, i;
    elemType x;
    struct data_container s, t, res;

    init(&s, 10);
    init(&t, 10);
    init(&res, 10);

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&s, i+1, x);
    }

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&t, i+1, x);
    }

    merge(&s, &t, &res);

    for (i = 0; i < res.n; i++)
        printf("%d ", res.pData[i]);

    /* 清空容器空间 */
    destroy(&s);
    destroy(&t);
    destroy(&res);

    return 0;
}

void merge(struct data_container* s, struct data_container* t, struct data_container* res)
{
    int i = s->n - 1;
    int j = t->n - 1;

    while (i >= 0 || j >= 0) {
        if (i < 0) {
            insert(res, res->n + 1, t->pData[j]);
            j--;
        } else if (j < 0) {
            insert(res, res->n + 1, s->pData[i]);
            i--;
        }
        else if (s->pData[i] > t->pData[j]) {
            insert(res, res->n + 1, s->pData[i]);
            i--;
        } else {
            insert(res, res->n + 1, t->pData[j]);
            j--;
        }
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

