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

    /* 一个浮点数据存储空间容器 */
    struct data_listcontainer s;
    struct data_node *p;

    /* 初始化容器空间 */
    init(&s);

    /* 在第i个位置前插入一个数b */
    while (scanf("%d", &b) != EOF)
        insert(&s, ++i, b);

    relink(&s);

    for (p = s.head->link; p->link != s.head->link; p = p->link)
        printf("%d ", p->data);

    printf("%d ", p->data);

    printf("\n");

    /* 清空容器空间 */
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

/* 初始化链表：建立一个头结点 */
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

/* 查找第i个数据 */
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
    if(q == NULL) {
        printf("memory allocation error\n");
        return;
    }
    q->data = b;

    /* 把新节点插入到第i个数据节点之前 */
    q->link = p->link;
    p->link = q;
}

void destroy(struct data_listcontainer *s)
{
    /* 清空容器 */
    struct data_node *p = s->head->link, *q;

    /* 释放容器中每一个节点 */
    while(p->link != s->head->link) {
        q = p->link; /* 保留下一个节点的地址 */
        free(p);
        p = q;
    }

    free(s->head);
    free(p);

    s->head = NULL;
}
