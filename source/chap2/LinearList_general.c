#include <stdio.h>

#define maxLen  100

typedef float elemType;
struct data_container
{
	elemType data[maxLen];
	int n;
};

void insert(struct data_container *s, int i, elemType b);
void del(struct data_container *s, int i);
int search(struct data_container *s, elemType b);

int main()
{
	int i, j;
	elemType b;

	// 一个浮点数据存储空间容器
	struct data_container s;

	// 在第i个位置前插入一个数b
	i = 1;
	b = 3.6;
	insert(&s, i, b);

	// 删除第i个整数
	i = 1;
	del(&s, i);

	// 查找数 b
	b = 2.2;
	j = search(&s, b);

	if(j < 0){
		printf("no found of %f\n", b);
	}
	else{
		printf("found of %f\n", b);
	}

    return 0;
}

void insert(struct data_container *s, int i, elemType b)
{
	// 在第i个位置前插入一个数b
	int j = 0;

	for(j = s->n-1; j >= (i-1); j --)
	{
		s->data[j+1] = s->data[j];
	}

	s->data[i-1] = b;
	s->n ++;
}

void del(struct data_container *s, int i)
{
	// 删除第i个整数
	int j = 0;

	for(j = i; j <= s->n-1; j ++)
	{
		s->data[j-1] = s->data[j];
	}

	s->n --;
}

int search(struct data_container *s, elemType b)
{
	// 查找整数 b
	int j = 0;

	for(j = 0; j <= s->n-1; j ++)
	{
		if(b == s->data[j])
			break;
	}

	return (j >= s->n ? -1: j+1);
}
