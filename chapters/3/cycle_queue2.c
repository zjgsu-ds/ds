#include <stdio.h>
#include <stdlib.h>

#define maxLen 100
typedef double elemType;
struct queue_container {
    elemType data[maxLen];
    int front, rear;
    int size;
};

void InitQueue(struct queue_container *s);
int EnQueue(struct queue_container *s,  elemType b);
int DeQueue(struct queue_container *s, elemType *b);
int HeadQueue(struct queue_container *s, elemType *b);

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
    DeQueue(&s, &b);

    return 0;
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

    *b = s->front;
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

    *b = s->front;

    return 1;
}




