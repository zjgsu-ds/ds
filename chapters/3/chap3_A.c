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

    /* 读取字符串 */
    gets(str);

    /* 初始化栈 */
    InitStack(&s);

    len = strlen(str);
    for (i = 0; i < len; i++) {
        curr = str[i];

        if (IsOpenChar(curr)) {          /* 如果当前是左括弧, 压栈 */
            Push(&s, curr);
        } else if (IsCloseChar(curr)) {  /* 如果是右括弧 */
            if (Empty(&s)) {             /* 栈为空, 则没有匹配的左括弧, 出错 */
                printf("NO\n");
                return 0;
            }

            prev = Pop(&s);

            if (!Matched(prev, curr)) { /* 左括弧与当前右括弧的类型不一致, 出错 */
                printf("NO\n");
                return 0;
            }
        }
    }

    if (Empty(&s))
        printf("YES\n");
    else /* 如果栈不为空, 则有左括弧没有匹配, 出错 */
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
