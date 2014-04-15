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

int main()
{
    int n, i, min_value;
    elemType b;
    struct data_node *p;

    /* 一个浮点数据存储空间容器 */
    struct data_listcontainer s;

    scanf("%d", &n);

    /* 初始化容器空间 */
    init(&s);

    for (i = 0; i < n; i++) {
        scanf("%d", &b);
        insert(&s, i+1, b);
    }

    min_value = s.head->next->data;
    for (p = s.head->next; p != NULL; p = p->next)
        if (p->data < min_value)
            min_value = p->data;

    printf("%d\n", min_value);


    /* 清空容器空间 */
    destroy(&s);

    return 0;
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

    node->next = NULL;
    s->head = node;
}

/* 查找第i个数据 */
struct data_node* find_helper(struct data_node *p, int i)
{
    if (i == 0 || p == NULL)
        return p;
    else
        return find_helper(p->next, i-1);

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
    q->next = p->next;
    p->next = q;
}

void destroy(struct data_listcontainer *s)
{
    /* 清空容器 */
    struct data_node *p = s->head, *q;

    /* 释放容器中每一个节点 */
    while(p != NULL) {
        q = p->next; /* 保留下一个节点的地址 */
        free(p);
        p = q;
    }

    s->head = NULL;
}
