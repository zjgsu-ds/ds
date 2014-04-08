
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
void inverse(struct data_listcontainer *s);

int main()
{
    int n, i;
    elemType x;
    struct data_node* p;

    /* 一个浮点数据存储空间容器 */
    struct data_listcontainer s;

    /* 初始化容器空间 */
    init(&s);

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&s, i + 1, x);
    }

    inverse(&s);

    p = s.head->next;

    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }

    /* 清空容器空间 */
    destroy(&s);

    return 0;
}

void inverse(struct data_listcontainer *s)
{
    struct data_node* pOld = s->head->next;
    struct data_node* pNew = NULL;
    struct data_node* pTemp;

    while (pOld) {
        pTemp = pOld->next;
        pOld->next = pNew;
        pNew = pOld;
        pOld = pTemp;
    }

    s->head->next = pNew;
}

/* 初始化链表：建立一个头结点 */
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

/* 查找第i个数据 */
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

/* 在位置i插入一个新数据节点 */
void insert(struct data_listcontainer *s, int i, elemType b)
{
    struct data_node *q = NULL;
    struct data_node *p = find(s, i-1); /* 找到第i-1个数据 */

    if (p == NULL) {
        printf("No such node, insertion failed.\n");
        return;
    }

    /* 为b分配一个节点空间 */
    q = (struct data_node *)malloc(sizeof(struct data_node));
    if(q == 0) {
        printf("memory allocation error\n");
        return;
    }
    q->data = b;

    /* 把新节点插入到第i个数据节点之前 */
    q->next = p->next;
    p->next = q;

    return;
}

void destroy(struct data_listcontainer *s)
{
    /* 清空容器 */
    struct data_node *p = s->head, *q;

    /* 释放容器中每一个节点 */
    while(p != 0) {
        q = p->next; /* 保留下一个节点的地址 */
        free(p);
        p = q;
    }

    s->head = 0;
}
