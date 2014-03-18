#include <stdio.h>
#include <stdlib.h>

typedef float elemType;
struct data_node {
    elemType data;
    struct data_node *next;
};

struct stack_listcontainer {
    struct data_node *top;
};

void InitStack(struct stack_listcontainer *s);
void Push(struct stack_listcontainer *s,  elemType b);
elemType Pop(struct stack_listcontainer *s);
int IsEmpty(struct stack_listcontainer *s);
int Count(struct stack_listcontainer *s);

int main()
{
    // 一个存储浮点数据的栈容器
    struct stack_listcontainer s;

    // 初始化栈容器
    InitStack(&s);

    // 在栈顶放多个元素
    Push(&s, 1.0);
    Push(&s, 2.0);
    Push(&s, 3.0);

    printf("Count: %d\n", Count(&s));

    // 出栈顶数据
    printf("Pop: %f\n", Pop(&s));

    printf("Count: %d\n", Count(&s));
    
    return 0;
}


void InitStack(struct stack_listcontainer *s)
{
    s->top = NULL;
}

void Push(struct stack_listcontainer *s,  elemType b)
{
    // 把数b放入栈中
    struct data_node *q = NULL;

    // 为b分配一个节点空间
    q = (struct data_node *)malloc(sizeof(struct data_node));
    if(q == NULL) {
        printf("memory allocation error\n");
        return;
    }
    q->data = b;

    // 把新节点插到栈顶
    q->next = s->top;
    s->top = q;
}

elemType Pop(struct stack_listcontainer *s)
{
    // 删除栈顶元素，并返回栈顶元素
    struct data_node *p = s->top->next;
    elemType b = s->top->data;

    // 释放栈顶节点
    free(s->top);
    s->top = p;

    return b;
}

int IsEmpty(struct stack_listcontainer *s)
{
    return s->top == NULL;
}

int Count(struct stack_listcontainer *s)
{
    int n = 0;
    struct data_node *p = s->top;

    while (p) {
        n++;
        p = p->next;
    }

    return n;
}


