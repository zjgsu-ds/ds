#include <stdio.h>
#include <stdlib.h>

typedef int elemType;
struct data_node {
    elemType data;
    struct data_node *link, *prev;
};

struct data_listcontainer {
    struct data_node *head;
};

void init(struct data_listcontainer *s);
void insert(struct data_listcontainer *s, int i, elemType b);
void destroy(struct data_listcontainer *s);

void relink(struct data_listcontainer *s);

int main()
{
    elemType b;
    int i = 0;

    /* һ���������ݴ洢�ռ����� */
    struct data_listcontainer s;
    struct data_node *p;

    /* ��ʼ�������ռ� */
    init(&s);

    /* �ڵ�i��λ��ǰ����һ����b */
    while (scanf("%d", &b) != EOF)
        insert(&s, ++i, b);

    relink(&s);

    for (p = s.head->link; p->link != s.head->link; p = p->link)
        printf("%d ", p->data);

    printf("%d ", p->data);

    printf("\n");

    /* ��������ռ� */
    destroy(&s);

    return 0;
}

void relink(struct data_listcontainer *s)
{
    struct data_node *p;

    if (s->head->link == NULL)
        return;

    for (p = s->head->link; p->link != NULL; p = p->link)
        p->link->prev = p;

    p->link = s->head->link;
    s->head->prev = p;
}

/* ��ʼ����������һ��ͷ��� */
void init(struct data_listcontainer *s)
{
    struct data_node *node = NULL;

    node = (struct data_node *)malloc(sizeof(struct data_node));
    if(node == NULL) {
        printf("memory allocation error\n");
        return;
    }

    node->link = NULL;
    s->head = node;
}

/* ���ҵ�i������ */
struct data_node* find_helper(struct data_node *p, int i)
{
    if (i == 0 || p == NULL)
        return p;
    else
        return find_helper(p->link, i-1);

}

struct data_node* find(struct data_listcontainer* s, int i)
{
    return find_helper(s->head, i);
}

/* ��λ��i����һ�������ݽڵ� */
void insert(struct data_listcontainer *s, int i, elemType b)
{
    struct data_node *q = NULL;
    struct data_node *p = find(s, i-1); /* �ҵ���i-1������ */

    if (p == NULL) {
        printf("No such node, insertion failed.\n");
        return;
    }

    /* Ϊb����һ���ڵ�ռ� */
    q = (struct data_node *)malloc(sizeof(struct data_node));
    if(q == NULL) {
        printf("memory allocation error\n");
        return;
    }
    q->data = b;

    /* ���½ڵ���뵽��i�����ݽڵ�֮ǰ */
    q->link = p->link;
    p->link = q;
}

void destroy(struct data_listcontainer *s)
{
    /* ������� */
    struct data_node *p = s->head->link, *q;

    /* �ͷ�������ÿһ���ڵ� */
    while(p->link != s->head->link) {
        q = p->link; /* ������һ���ڵ�ĵ�ַ */
        free(p);
        p = q;
    }

    free(s->head);
    free(p);

    s->head = NULL;
}
