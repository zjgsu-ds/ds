#include <stdio.h>

const int maxLen = 100;
typedef float elemType;
struct stack_container {
    elemType data[maxLen];
    int top;
};

void InitStack(struct stack_container *s);
void Push(struct stack_container *s,  elemType b);
elemType Pop(struct stack_container *s);

int main()
{
    elemType b;

    // 一个存储浮点数据的栈容器
    struct stack_container s;

    // 初始化栈容器
    InitStack(&s);

    // 在栈顶放入一个数b
    b = 3.6;
    Push(&s, b);

    // 出栈顶数据
    b = Pop(&s);

    return 0;
}


void InitStack(struct stack_container *s)
{
    s->top = 0;
}

void Push(struct stack_container *s,  elemType b)
{
    // 把数b放入栈中
    s->data[s->top] = b;
    s->top++;

    return;
}

elemType Pop(struct stack_container *s)
{
    // 删除栈顶元素，并返回栈顶元素
    s->top--;
    return s->data[s->top];
}


