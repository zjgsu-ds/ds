#include <stdio.h>
#include <string.h>

const int maxLen = 100;
typedef char* elemType;
struct stack_container {
    elemType data[maxLen];
    int top;
};

void InitStack(struct stack_container *s);
void Push(struct stack_container *s,  elemType b);
elemType Pop(struct stack_container *s);

int main()
{
    char str[100];
    int len, i;
    struct stack_container s;

    // 读取字符串
    while (gets(str)) {
        len = strlen(str);

        str[0] = ' ';
        str[len-1] = '\0'; /* 忽略最后一个双引号 */

        // 初始化栈容器
        InitStack(&s);

        for (i = 0; i < len; i++) {
            if (str[i] == ' ') {
                str[i] = '\0';
                Push(&s, str + i + 1);
            }
        }

        putchar('"');
        while (s.top != 0) {
            printf("%s", Pop(&s));
            if (s.top > 0)
                putchar(' ');
        }
        putchar('"');
        putchar('\n');
    }

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
