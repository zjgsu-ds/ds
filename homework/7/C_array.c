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
void del(struct data_container *s, int i);
void unique(struct data_container *s);

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

    unique(&s);

    for (i = 0; i < s.n; i++)
        printf("%d ", s.pData[i]);

    /* ��������ռ� */
    destroy(&s);

    return 0;
}

void unique(struct data_container* s)
{
    int i = 1;

    while (i < s->n) {
        if (s->pData[i] == s->pData[i-1])
            del(s, i+1);
        else
            i++;
    }
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

    s->n--;
}

