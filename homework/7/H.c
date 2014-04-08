#include <stdio.h>
#include <string.h>

const int maxLen = 100;
typedef char elemType;
struct stack_container {
    elemType data[maxLen];
    int top;
};

void InitStack(struct stack_container *s);
void Push(struct stack_container *s,  elemType b);
elemType Pop(struct stack_container *s);
void Clear(struct stack_container *s);

int main()
{
    struct stack_container s;
    char str[100];
    int n, i;

    InitStack(&s);

    gets(str);
    n = strlen(str);

    for (i = 0; i < n; i++) {
        if (str[i] == '#')
            Pop(&s);
        else if (str[i] == '@')
            Clear(&s);
        else
            Push(&s, str[i]);
    }

    for (i = 0; i < s.top; i++)
        putchar(s.data[i]);

    putchar('\n');

    return 0;
}


void InitStack(struct stack_container *s)
{
    s->top = 0;
}

void Clear(struct stack_container *s)
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


