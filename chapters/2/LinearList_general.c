#include <stdio.h>

#define maxLen  100

typedef float elemType;
struct data_container {
    elemType data[maxLen];
    int n;
};

void init(struct data_container* s);
void insert(struct data_container *s, int i, elemType b);
void del(struct data_container *s, int i);
int search(struct data_container *s, elemType b);

int main()
{
    int i, j;
    elemType b;

    /* һ���������ݴ洢�ռ����� */
    struct data_container s;

    init(&s);

    /* �ڵ�i��λ�ò���һ����b */
    i = 1;
    b = 3.6;
    insert(&s, i, b);

    /* �ڵ�i��λ�ò���һ����b */
    i = 2;
    b = 2.2;
    insert(&s, i, b);

    /* ɾ����i������*/
    i = 1;
    del(&s, i);

    /* ������ b */
    b = 2.2;
    j = search(&s, b);

    if(j < 0)
        printf("%f not found\n", b);
    else
        printf("%f found\n", b);

    return 0;
}

void init(struct data_container* s)
{
    s->n = 0;
}

/* �ڵ�i��λ��ǰ����һ����b */
void insert(struct data_container *s, int i, elemType b)
{
    int j = 0;

    for(j = s->n-1; j >= (i-1); j--)
        s->data[j+1] = s->data[j];

    s->data[i-1] = b;
    s->n++;
}

/* ɾ����i������ */
void del(struct data_container *s, int i)
{
    int j = 0;

    for(j = i; j <= s->n-1; j++)
        s->data[j-1] = s->data[j];

    s->n--;
}

/* �������� b */
int search(struct data_container *s, elemType b)
{
    int j = 0;

    for(j = 0; j <= s->n-1; j++)
        if(b == s->data[j])
            break;

    return (j >= s->n ? -1: j+1);
}
