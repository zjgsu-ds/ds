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

    // һ���洢�������ݵ�ջ����
    struct stack_container s;

    // ��ʼ��ջ����
    InitStack(&s);

    // ��ջ������һ����b
    b = 3.6;
    Push(&s, b);

    // ��ջ������
    b = Pop(&s);

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


