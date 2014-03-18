#include <stdio.h>
#include <stdlib.h>

typedef char elemType;
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

int Length(struct data_listcontainer *s);
elemType getElem(struct data_listcontainer *s, int i);
void Union(struct data_listcontainer *LA, struct data_listcontainer *LB);
void print_list(struct data_listcontainer* s);

int main()
{
    int i;
    char line[128];

    /* 两个存储空间容器，分别存放集合A和B */
    struct data_listcontainer LA, LB;

    /* 初始化空容器 */
    init(&LA);
    init(&LB);

    /* 输入集合A的数据 */
    printf("输入A:\n");
    fgets(line, 128, stdin);
    i = 0;

    while(line[i] != '\n') {
        /* 读出line中的每个字符,并插入到容器的末尾 */
        insert(&LA, i+1, line[i]);
        i++;
    }

    /* 输入集合B的数据 */
    printf("输入B:\n");
    fgets(line, 128, stdin);
    i = 0;

    while(line[i] != '\n') {
        /* 读出line中的每个字符,并插入到容器的末尾 */
        insert(&LB, i+1, line[i]);
        i++;
    }

    /* 合并集合A和B，合并数据存在集合A中 */
    Union(&LA, &LB);

    printf("Result: \n");
    print_list(&LA);

    /* 释放容器空间 */
    destroy(&LA);
    destroy(&LB);

    return 0;
}

/* 将所有在LB中存在而LA中不存在的数据插入到LA中 */
void Union(struct data_listcontainer *LA, struct data_listcontainer *LB)
{
    int nA = Length(LA);
    int nB = Length(LB);
    int i;

    for(i = 1; i <= nB; i++) {
        /* 获得容器LB中的第i个数据 */
        elemType d = getElem(LB, i);

        /* 把数据插入到容器LA的第i个数据之前 */
        if (search(LA, d) < 0) {
            nA++;
            insert(LA, nA, d);
        }
    }

    return;
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

/* 插入一个新数据节点 */
void insert(struct data_listcontainer *s, int i, elemType b)
{
    struct data_node* p = find(s, i-1);
    struct data_node *q = 0;

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

/* 删除第i个数据节点 */
void del(struct data_listcontainer *s, int i)
{
    struct data_node *p = find(s, i-1);
    struct data_node *q;
    int j = 1;

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

    while(p != 0) {
        if(p->data == b) {
            return j;
        }

        p = p->next;
        j++;
    }

    return -1;
}

/* 清空容器 */
void destroy(struct data_listcontainer *s)
{
    struct data_node *p = s->head, *q;

    /* 释放容器中每一个节点 */
    while(p != 0) {
        q = p->next; /* 保留下一个节点的地址 */
        free(p);
        p = q;
    }

    s->head = 0;
}

/* 计算容器中的数据个数 */
int Length(struct data_listcontainer *s)
{
    struct data_node *p= s->head->next;
    int n = 0;

    while(p) {
        n++;
        p = p->next;
    }

    return n;
}

/* 打印链表 */
void print_list(struct data_listcontainer* s)
{
    struct data_node* p = s->head->next;

    while (p) {
        putchar(p->data);
        p = p->next;
    }

    putchar('\n');
}

/* 获得容器中的第i个数据 */
elemType getElem(struct data_listcontainer *s, int i)
{
    return find(s, i)->data;
}
