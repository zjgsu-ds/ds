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

    // ��ʼ��ջ����
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
    // ����b����ջ��
    s->data[s->top] = b;
    s->top++;

    return;
}

elemType Pop(struct stack_container *s)
{
    // ɾ��ջ��Ԫ�أ�������ջ��Ԫ��
    s->top--;
    return s->data[s->top];
}


