
#include <stdio.h>
#include <stdlib.h>

typedef int elemType;
struct data_node {
    elemType data;
    struct data_node *next;
};

struct data_listcontainer {
    struct data_node *head;
};

void init(struct data_listcontainer *s);
void insert(struct data_listcontainer *s, int i, elemType b);
void destroy(struct data_listcontainer *s);
void merge(struct data_listcontainer *s, struct data_listcontainer *t);

int main()
{
    int n, i;
    elemType x;
    struct data_node* p;

    /* һ���������ݴ洢�ռ����� */
    struct data_listcontainer s, t;

    /* ��ʼ�������ռ� */
    init(&s);
    init(&t);

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&s, i + 1, x);
    }

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&t, i + 1, x);
    }

    merge(&s, &t);

    p = s.head->next;

    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }

    /* ��������ռ� */
    destroy(&s);
    destroy(&t);

    return 0;
}

struct data_node* push_front(struct data_listcontainer* s, struct data_node* p) {
    struct data_node* tmp = p->next;
    p->next = s->head->next;
    s->head->next = p;

    return tmp;
}

void merge(struct data_listcontainer *s, struct data_listcontainer *t)
{
    struct data_node *p = s->head->next;
    struct data_node *q = t->head->next;

    s->head->next = NULL;
    t->head->next = NULL;

    while (p || q) {
        if (!p)
            q = push_front(s, q);
        else if (!q)
            p = push_front(s, p);
        else if (p->data < q->data)
            p = push_front(s, p);
        else
            q = push_front(s, q);
    }
}

/* ��ʼ����������һ��ͷ��� */
void init(struct data_listcontainer *s)
{
    struct data_node *node = 0;

    node = (struct data_node *)malloc(sizeof(struct data_node));
    if(node == 0) {
        printf("memory allocation error\n");
        return;
    }

    node->next = 0;
    s->head = node;
    return;
}

/* ���ҵ�i������ */
struct data_node* find(struct data_listcontainer* s, int i)
{
    struct data_node* p = s->head;
    int j = 0;

    if (i < 0)
        return NULL;

    while (j < i) {
        p = p->next;
        ++j;
    }

    return p;
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
    if(q == 0) {
        printf("memory allocation error\n");
        return;
    }
    q->data = b;

    /* ���½ڵ���뵽��i�����ݽڵ�֮ǰ */
    q->next = p->next;
    p->next = q;

    return;
}

void destroy(struct data_listcontainer *s)
{
    /* ������� */
    struct data_node *p = s->head, *q;

    /* �ͷ�������ÿһ���ڵ� */
    while(p != 0) {
        q = p->next; /* ������һ���ڵ�ĵ�ַ */
        free(p);
        p = q;
    }

    s->head = 0;
}
