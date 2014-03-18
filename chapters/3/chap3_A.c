#include <stdio.h>
#include <string.h>

typedef char elemType;
struct stack_container {
    elemType data[1000];
    int top;
};

void InitStack(struct stack_container *s);
void Push(struct stack_container *s,  elemType b);
elemType Pop(struct stack_container *s);
int Empty(struct stack_container *s);
int Matched(char prev, char curr);
int IsOpenChar(char c);
int IsCloseChar(char c);

int main()
{
    struct stack_container s;
    char str[100];
    char prev, curr;
    int len, i;

    /* ��ȡ�ַ��� */
    gets(str);

    /* ��ʼ��ջ */
    InitStack(&s);

    len = strlen(str);
    for (i = 0; i < len; i++) {
        curr = str[i];

        if (IsOpenChar(curr)) {          /* �����ǰ��������, ѹջ */
            Push(&s, curr);
        } else if (IsCloseChar(curr)) {  /* ����������� */
            if (Empty(&s)) {             /* ջΪ��, ��û��ƥ���������, ���� */
                printf("NO\n");
                return 0;
            }

            prev = Pop(&s);

            if (!Matched(prev, curr)) { /* �������뵱ǰ�����������Ͳ�һ��, ���� */
                printf("NO\n");
                return 0;
            }
        }
    }

    if (Empty(&s))
        printf("YES\n");
    else /* ���ջ��Ϊ��, ����������û��ƥ��, ���� */
        printf("NO\n");

    return 0;
}

void InitStack(struct stack_container *s)
{
    s->top = 0;
}

int IsOpenChar(char c)
{
    return c == '(' || c == '[' || c == '{';
}

int IsCloseChar(char c)
{
    return c == ')' || c == ']' || c == '}';
}

int Matched(char prev, char curr)
{
    return (prev == '(' && curr == ')') || (prev == '[' && curr == ']') || (prev == '{' && curr == '}');
}

int Empty(struct stack_container *s)
{
    return s->top == 0;
}

void Push(struct stack_container *s,  elemType b)
{
    s->data[s->top] = b;
    s->top++;

    return;
}

elemType Pop(struct stack_container *s)
{
    s->top--;
    return s->data[s->top];
}
