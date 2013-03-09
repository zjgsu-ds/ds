
#include <stdio.h>
#include <stdlib.h>

typedef float elemType;
struct data_node
{
    elemType data;
    struct data_node *next;
};

struct data_listcontainer
{
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

    // 一个浮点数据存储空间容器
    struct data_listcontainer s;

    // 初始化容器空间
    init(&s);

    // 在第i个位置前插入一个数b
    i = 1;
    b = 3.6;
    insert(&s, i, b);

    // 删除第i个整数
    i = 1;
    del(&s, i);

    // 查找数 b
    b = 3.6;
    j = search(&s, b);

    if(j < 0){
        printf("no found of %f\n", b);
    }
    else{
        printf("found of %f\n", b);
    }

    // 清空容器空间
    destroy(&s);

    return 0;
}

void init(struct data_listcontainer *s)
{
    // 初始化链表：建立一个头结点
    struct data_node *node = 0;

    node = (struct data_node *)malloc(sizeof(struct data_node));
    if(node == 0){
        printf("memory allocation error\n");
        return;
    }

    node->next = 0;
    s->head = node;
    return;
}

/* find i-th element, use 1-based index */
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

void insert(struct data_listcontainer *s, int i, elemType b)
{
    // 插入一个新数据节点
    struct data_node *q = NULL;
    struct data_node *p = find(s, i-1); /* 找到第i-1个数据 */

    if (p == NULL) {
        printf("No such node, insertion failed.\n");
        return;
    }

    // 为b分配一个节点空间
    q = (struct data_node *)malloc(sizeof(struct data_node));
    if(q == 0){
        printf("memory allocation error\n");
        return;
    }
    q->data = b;

    // 把新节点插入到第i个数据节点之前
    q->next = p->next;
    p->next = q;

    return;
}

void del(struct data_listcontainer *s, int i)
{
    // 删除第i个数据节点
    struct data_node *q;
    struct data_node *p = find(s, i-1); /* 找到第i-1个数据 */

    // 修改指针：把第i个节点从链表中移出
    q = p->next;
    p->next = q->next;

    // 释放节点内存
    free(q);
}

int search(struct data_listcontainer *s, elemType b)
{
    // 查找容器中是否存在数b.
    // 如果存放,返回其首次出现的位置;否则返回-1
    struct data_node *p = s->head->next;
    int j = 1;

    while(p != 0)
    {
        if(p->data == b)
        {
            return j;
        }

        p = p->next;
        j ++;
    }

    return -1;
}

void destroy(struct data_listcontainer *s)
{
    // 清空容器
    struct data_node *p = s->head, *q;

    // 释放容器中每一个节点
    while(p != 0)
    {
        q = p->next; // 保留下一个节点的地址
        free(p);
        p = q;
    }

    s->head = 0;
}
