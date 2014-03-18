#include <stdio.h>

#define maxLen  100
#define TRUE 1
#define FALSE 0

typedef char elemType;
struct data_container {
    elemType data[maxLen];
    int n;
};

int insert(struct data_container *s, int i, elemType b);
int del(struct data_container *s, int i);
int search(struct data_container *s, elemType b);
int Length(struct data_container *s);
elemType getElem(struct data_container *s, int i);
void Union(struct data_container *LA, struct data_container *LB);

int main()
{
    int i;
    char line[128];

    /* �����洢�ռ��������ֱ��ż���A��B */
    struct data_container LA, LB;

    /* ��ʼ�������� */
    LA.n = 0;
    LB.n = 0;

    /* ���뼯��A������ */
    printf("����A: \n");
    fgets(line, 128, stdin);
    i = 0;

    while(line[i] != '\n') {
        /* ����line�е�ÿ���ַ�,�����뵽������ĩβ */
        insert(&LA, LA.n+1, line[i]);
        i++;
    }

    /* ���뼯��B������ */
    printf("����B: \n");
    fgets(line, 128, stdin);
    i = 0;

    while(line[i] != '\n') {
        /* ����line�е�ÿ���ַ�,�����뵽������ĩβ */
        insert(&LB, LB.n+1, line[i]);
        i++;
    }

    /* �ϲ�����A��B���ϲ����ݴ��ڼ���A�� */
    Union(&LA, &LB);

    printf("Result:\n");

    for (i = 0; i < LA.n;++i)
        putchar(LA.data[i]);

    putchar('\n');

    return 0;
}

/* ��������LB�д��ڶ�LA�в����ڵ����ݲ��뵽LA�� */
void Union(struct data_container *LA, struct data_container *LB)
{
    int i;

    for(i = 1; i <= LB->n; i++) {
        /* �������LB�еĵ�i������ */
        elemType d = getElem(LB, i);

        /* �����ݲ��뵽����LA�ĵ�i������֮ǰ */
        if (search(LA, d) < 0)
            insert(LA, LA->n + 1, d);
    }

    return;
}

/* �ڵ�i��λ�ò���һ����b */
int insert(struct data_container *s, int i, elemType b)
{
    int j = 0;

    /* �������Ϸ���
       ����λ��ֻ���ڷ�Χ[1, n+1]�������㹻�Ĵ洢�ռ�
     */
    if(i < 0 || i > (s->n+1) || s->n == maxLen)
        return FALSE;


    for(j = s->n-1; j >= (i-1); j--)
        s->data[j+1] = s->data[j];

    s->data[i-1] = b;
    s->n++;

    return TRUE;
}

/* ɾ����i������ */
int del(struct data_container *s, int i)
{
    int j = 0;

    /* �������Ϸ���
       i�ķ�ΧΪ:[1, n]
    */
    if(i < 0 || i > s->n)
        return FALSE;

    for(j = i; j <= s->n-1; j++)
        s->data[j-1] = s->data[j];

    s->n--;

    return TRUE;
}

/* �������� b */
int search(struct data_container *s, elemType b)
{
    int j = 0;

    for(j = 0; j < s->n; j++)
        if(b == s->data[j])
            break;

    return (j >= s->n ? -1: j+1);
}

/* ���������е����ݸ��� */
int Length(struct data_container *s)
{
    return s->n;
}

/* �������s�еĵ�i������ */
elemType getElem(struct data_container *s, int i)
{
    return s->data[i-1];
}


