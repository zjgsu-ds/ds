#include <stdio.h>

const int maxLen = 100;
typedef char elemType;
struct stack_container {
    elemType data[maxLen];
    int top;
};

void InitStack(struct stack_container *s);
void Push(struct stack_container *s,  elemType b);
elemType Pop(struct stack_container *s);

int main()
{
    char str[128];
    int i;
    // 一个存储浮点数据的栈容器
    struct stack_container s;

    gets(str);

    // 初始化栈容器
    InitStack(&s);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '&')
            break;
        else
            Push(&s, str[i]);
    }

    if (str[i] == '\0') {
        printf("NO\n");
        return 0;
    }

    i++;
    while (str[i] != '\0') {
       if (s.top == 0 || Pop(&s) != str[i]) {
           printf("NO\n");
           return 0;
       }

      i++; 
    }

    printf("YES\n");

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


