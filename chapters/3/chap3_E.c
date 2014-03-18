#include <stdio.h>

const int maxLen = 100;
typedef int elemType;
struct stack_container {
    elemType data[maxLen];
    int top;
};

void InitStack(struct stack_container *s);
void Push(struct stack_container *s,  elemType b);
elemType Pop(struct stack_container *s);
int Empty(struct stack_container* s);
void enum_stack(struct stack_container data, struct stack_container stack, struct stack_container result);
void print_stack(struct stack_container *s);

int main()
{
    int n, i;
    struct stack_container data, stack, result;

    scanf("%d", &n);

    InitStack(&data);
    InitStack(&stack);
    InitStack(&result);

    data.top = n;
    for (i = n-1; i >= 0; i--)
        scanf("%d", &data.data[i]);

    enum_stack(data, stack, result);

    return 0;
}

void enum_stack(struct stack_container data, struct stack_container stack, struct stack_container result)
{
    if (Empty(&data) && Empty(&stack)) {
        print_stack(&result);
        return;
    } else {
        if (!Empty(&stack)) {
            struct stack_container new_stack = stack;
            struct stack_container new_result = result;
            Push(&new_result, Pop(&new_stack));
            enum_stack(data, new_stack, new_result);
        }

        if (!Empty(&data)) {
            struct stack_container new_data = data;
            struct stack_container new_stack = stack;
            Push(&new_stack, Pop(&new_data));
            enum_stack(new_data, new_stack, result);
        }
    }
}

void print_stack(struct stack_container *s)
{
    int i;

    for (i = 0; i < s->top; i++)
        printf("%d%c", s->data[i], i == s->top-1 ? '\n' : ' ');
}

void InitStack(struct stack_container *s)
{
    s->top = 0;
}

int Empty(struct stack_container *s)
{
    return s->top == 0;
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


