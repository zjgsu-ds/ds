#include <stdio.h>

#define maxLen 100
typedef float elemType;
struct queue_container {
    elemType data[maxLen];
    int front, rear;
};

void InitQueue(struct queue_container *s);
void EnQueue(struct queue_container *s,  elemType b);
void DeQueue(struct queue_container *s);

int main()
{
    elemType b;

    // 一个存储浮点数据的循环队列容器
    struct queue_container s;

    // 初始化栈容器
    InitQueue(&s);

    // 在队尾放入一个数b
    b = 3.6;
    EnQueue(&s, b);

    // 出队头数据
    DeQueue(&s);

    return 0;
}


void InitQueue(struct queue_container *s)
{
    s->front = s->rear = 0;
}

void EnQueue(struct queue_container *s,  elemType b)
{
    // 把数b放入队列
    s->data[s->rear] = b;
    s->rear = (s->rear+1) % maxLen;

    return;
}

void DeQueue(struct queue_container *s)
{
    // 删除队头元素
    s->front = (s->front+1) % maxLen;
}




