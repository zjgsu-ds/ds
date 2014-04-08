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

    scanf("A����Ϊ ");

    i = 1;
    while (scanf("%d", &x) == 1)
        insert(&s, i++, x);

    scanf("B����Ϊ ");

    i = 1;
    while (scanf("%d", &x) == 1)
        insert(&t, i++, x);

    if (subseq(&s, &t))
        printf("��");

    /* ��������ռ� */
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

/* ��ʼ�����������Ĵ洢�ռ� */
void init(struct data_container *s, int size)
{
    s->pData = (elemType*)malloc(sizeof(elemType) * size);
    s->size = size;
    s->n = 0;
}

/* ������������Ĵ洢�ռ� */
void destroy(struct data_container *s)
{
    free(s->pData);
    s->size = 0;
    s->n = 0;
}

/* �ڵ�i��λ�ò���һ����b */
void insert(struct data_container *s, int i, elemType b)
{
    int j = 0;

    if(s->n == s->size) { /* �����ռ䲻�� */
        // Ϊ���������µĸ���ռ�
        elemType *pNewData = (elemType*) malloc ( sizeof(elemType) * 2*s->size);

        // ��ԭ�ռ��������Ƶ��¿ռ���
        for(j = 0; j < s->n; j ++) {
            pNewData[j] = s->pData[j];
        }

        // ���¿ռ��滻�ɿռ�
        free(s->pData);
        s->pData = pNewData;
        s->size = 2*s->size;
    }

    // ������b
    for(j = s->n-1; j >= (i-1); j --) {
        s->pData[j+1] = s->pData[j];
    }

    s->pData[i-1] = b;
    s->n ++;
}

