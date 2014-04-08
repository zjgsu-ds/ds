
#include <stdio.h>
#include <stdlib.h>

typedef float elemType;
struct data_container {
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

    /* һ���������ݴ洢�ռ����� */
    struct data_container s;

    /* ��ʼ�������ռ� */
    init(&s, 10);

    /* �ڵ�i��λ�ò���һ����b */
    i = 1;
    b = 3.6;
    insert(&s, i, b);

    /* �ڵ�i��λ�ò���һ����b */
    i = 2;
    b = 2.2;
    insert(&s, i, b);

    /* ɾ����i������ */
    i = 1;
    del(&s, i);

    /* ������ b */
    b = 2.2;
    j = search(&s, b);

    if(j < 0)
        printf("%f not found\n", b);
    else
        printf("%f found\n", b);

    /* ��������ռ� */
    destroy(&s);

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

void del(struct data_container *s, int i)
{
    // ɾ����i������
    int j = 0;

    for(j = i; j <= s->n-1; j ++) {
        s->pData[j-1] = s->pData[j];
    }

    s->n --;
}

int search(struct data_container *s, elemType b)
{
    // �������� b
    int j = 0;

    for(j = 0; j <= s->n-1; j ++) {
        if(b == s->pData[j])
            break;
    }

    return (j >= s->n ? -1: j+1);
}
