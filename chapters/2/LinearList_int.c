
#include <stdio.h>

#define maxLen 100
struct data_container {
    int data[maxLen];
    int n;
};

void init(struct data_container* s);
void insert(struct data_container *s, int i, int b);
void del(struct data_container *s, int i);
int search(struct data_container *s, int b);

int main()
{
    int i, b, j;

    /* һ�����ݴ洢�ռ����� */
    struct data_container s;

    init(&s);

    /* �ڵ�i��λ�ò���һ����b */
    i = 1;
    b = 3;
    insert(&s, i, b);

    /* �ڵ�i��λ�ò���һ����b */
    i = 2;
    b = 4;
    insert(&s, i, b);

    /* ɾ����i������ */
    i = 2;
    del(&s, i);

    /* �������� b */
    b = 3;
    j = search(&s, b);

    if(j < 0)
        printf("%d not found\n", b);
    else
        printf("%d found\n", b);

    return 0;
}

void init(struct data_container* s)
{
    s->n = 0;
}

/* �ڵ�i��λ�ò���һ����b */
void insert(struct data_container *s, int i, int b)
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
int search(struct data_container *s, int b)
{
    int j = 0;

    for(j = 0; j <= s->n-1; j++)
        if(b == s->data[j])
            break;

    return (j >= s->n ? -1: j+1);
}
