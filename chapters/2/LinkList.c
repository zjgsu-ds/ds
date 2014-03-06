
#include <stdio.h>
#include <stdlib.h>

typedef float elemType;
struct data_node {
    elemType data;
    struct data_node *next;
};

struct data_listcontainer {
    struct data_node *head;
};

void init(struct data_listcontainer *s);
void insert(struct data_listcontainer *s, int i, elemType b);
void del(struct data_listcontainer *s, int i);
int search(struct data_listcontainer *s, elemType b);
void destroy(struct data_listcontainer *s);

int main()
{
    int i, j;
    elemType b;

    /* 一个浮点数据存储空间容器 */
    struct data_listcontainer s;

    /* 初始化容器空间 */
    init(&s);

    /* 在第i个位置前插入一个数b */
    i = 1;
    b = 3.6;
    insert(&s, i, b);

    /* 在第i个位置前插入一个数b */
    i = 2;
    b = 2.2;
    insert(&s, i, b);

    /* 删除第i个整数 */
    i = 2;
    del(&s, i);

    /* 查找数 b */
    b = 3.6;
    j = search(&s, b);

    if(j < 0)
        printf("%f not found\n", b);
    else
        printf("%f found\n", b);

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
struct data_node* find(struct data_listcontainer* s, int i)
{
    struct data_node* p = s->head;
    int current_index = 0;

    if (i < 0)
        return NULL;

    while (current_index < i && p != NULL) {
        p = p->next;
        ++current_index;
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
    if(q == NULL) {
        printf("memory allocation error\n");
        return;
    }
    q->data = b;

    /* 把新节点插入到第i个数据节点之前 */
    q->next = p->next;
    p->next = q;
}

void del(struct data_listcontainer *s, int i)
{
    /* 删除第i个数据节点 */
    struct data_node *q;
    struct data_node *p = find(s, i-1); /* 找到第i-1个数据 */

    /* 修改指针：把第i个节点从链表中移出 */
    q = p->next;
    p->next = q->next;

    /* 释放节点内存 */
    free(q);
}

/* 查找容器中是否存在数b.
   如果存放,返回其首次出现的位置;否则返回-1
 */
int search(struct data_listcontainer *s, elemType b)
{
    struct data_node *p = s->head->next;
    int j = 1;

    while(p != NULL) {
        if(p->data == b) {
            return j;
        }

        p = p->next;
        j++;
    }

    return -1;
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
