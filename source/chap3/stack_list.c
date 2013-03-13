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

int main()
{
    elemType b;

    // 一个存储浮点数据的栈容器
    struct stack_listcontainer s;

    // 初始化栈容器
    InitStack(&s);

    // 在栈顶放入一个数b
    b = 3.6;
    Push(&s, b);

    // 出栈顶数据
    b = Pop(&s);

    return 0;
}


void InitStack(struct stack_listcontainer *s)
{
    s->top = 0;
}

void Push(struct stack_listcontainer *s,  elemType b)
{
    // 把数b放入栈中
    struct data_node *q = 0;

    // 为b分配一个节点空间
    q = (struct data_node *)malloc(sizeof(struct data_node));
    if(q == 0) {
        printf("memory allocation error\n");
        return;
    }
    q->data = b;

    // 把新节点插到栈顶
    q->next = s->top;
    s->top = q;

    return;
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


