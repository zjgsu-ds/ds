#include "stdio.h"
#include "stdlib.h"

#define maxLen  100
typedef int elemType;
struct queue_container {
    elemType data[maxLen];
    int front, rear;
    int size;
};

void InitQueue(struct queue_container *s);
int EnQueue(struct queue_container *s,  elemType b);
int DeQueue(struct queue_container *s, elemType *b);
int HeadQueue(struct queue_container *s, elemType *b);
void PrintYangHuiTriangle(int n);

int main()
{
    int row = 0;
    char yes;

    while(1) {
        // 输入参数
        printf("Please Input Row of YangHui Triangle:");
        scanf("%d", &row);

        PrintYangHuiTriangle(row);

        // 是否继续
        printf("Continue? (Y/N)");
        yes = getchar();
        printf("\n");

        if(yes != 'y' && yes != 'Y') {
            break;
        }
    }

    return 0;
}

void PrintYangHuiTriangle(int n)
{
    // 打印n行杨辉三角
    int i = 0, k;
    elemType s, e;

    // 一个存储整数的循环队列容器
    struct queue_container q;
    InitQueue(&q);

    // 第一行元素
    EnQueue(&q, 0);
    EnQueue(&q, 1);
    EnQueue(&q, 1);
    EnQueue(&q, 0);

    for(i = 1; i <= n; i ++) {
        // 打印第i行元素,并计算第i+1行元素

        // 到第i行起始位置
        for(k = 1; k <= (n-i); k ++) {
            printf(" ");
        }

        // 两两取出第i行的元素,并计算第i+1行的相应元素
        if(i < n)
            EnQueue(&q, 0); // 第i+1行起头0元素
        do {
            DeQueue(&q, &s);
            HeadQueue(&q, &e);
            if(e != 0)
                printf("%d ", e); // 打印第i行的该元素
            if(i < n)
                EnQueue(&q, s+e); // 计算第i+1行的对应元素
        } while(e != 0); // e == 0: 第i行元素已取完

        printf("\n"); // 第i行打印结束
        DeQueue(&q, &s); // 删除第i行末尾0元素
        if(i < n)
            EnQueue(&q, 0); // 第i+1行结尾0元素
    }

    return;
}

void InitQueue(struct queue_container *s)
{
    s->front = s->rear = 0;
    s->size = 0;
}

int EnQueue(struct queue_container *s,  elemType b)
{
    // 把数b放入队列
    if(s->size == maxLen) {
        // 队列已满
        return -1;
    }

    s->data[s->rear] = b;
    s->rear = (s->rear+1) % maxLen;
    s->size ++;

    return 1;
}

int DeQueue(struct queue_container *s, elemType *b)
{
    // 删除队头元素
    if(s->rear == s->front) {
        // 队列为空
        return -1;
    }

    *b = s->data[s->front];
    s->front = (s->front+1) % maxLen;
    s->size --;

    return 1;
}

int HeadQueue(struct queue_container *s, elemType *b)
{
    // 读取队头元素
    if(s->rear == s->front) {
        // 队列为空
        return -1;
    }

    *b = s->data[s->front];

    return 1;
}




