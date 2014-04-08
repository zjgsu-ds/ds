#include <stdio.h>

#define maxLen 100
typedef int elemType;
struct stack_container {
    elemType data[maxLen];
    int top;
};

void InitStack(struct stack_container *s);
void Push(struct stack_container *s,  elemType b);
elemType Pop(struct stack_container *s);

int main()
{
    int n;
    struct stack_container s;

    // 初始化栈容器
    InitStack(&s);

    scanf("%d", &n);

    while (n != 0) {
        Push(&s, n%8);
        n /= 8;
    }

    while (s.top != 0)
        printf("%d", Pop(&s));

    printf("\n");

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


