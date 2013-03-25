#include <string.h>
#include <stdlib.h>

typedef int elemType;
struct array_container
{
    elemType *data;
    int *dimSize;
    int dim;
};

void CreateArray(struct array_container *s, int dimSize[], int dim);
elemType GetArrayElem(struct array_container *s, int elemSub[]);
void SetArrayElem(struct array_container *s, int elemSub[], elemType b);

int main()
{
    elemType b;
    int dimSize[2], elemSub[2]; // 2维数组

    // 一个存储整型数据的数组容器
    struct array_container s;

    // 创建一个3*4数组
    dimSize[1] = 3;
    dimSize[0] = 4;
    CreateArray(&s, dimSize, 2);

    // 修改数组中的第一行第二列元素
    elemSub[1] = 1;
    elemSub[0] = 2;
    b = 5;
    SetArrayElem(&s, elemSub, b);

    // 读取数组中的第二行第三列元素
    elemSub[1] = 2;
    elemSub[0] = 3;
    b = GetArrayElem(&s, elemSub);

    return 0;
}


void CreateArray(struct array_container *s, int dimSize[], int dim)
{
    // 创建一个dim维的数组
    int i, size = 1;

    // 计算数组大小
    s->dim = dim;
    s->dimSize = (int *)malloc(sizeof(int)*dim);
    for(i = 0; i < dim; i ++)
    {
        s->dimSize[i] = dimSize[i];
        size *= dimSize[i];
    }

    // 分配数组存储空间
    s->data = (elemType *)malloc(sizeof(elemType)*size);
}

elemType GetArrayElem(struct array_container *s, int elemSub[])
{
    int i, pos = 0, dim = s->dim;

    for(i = dim; i >= 2; i -- )
    {
        pos += pos * s->dimSize[i-2] + (elemSub[i-1]-1) * s->dimSize[i-2];
    }
    pos += elemSub[0]-1;

    return s->data[pos];
}

void SetArrayElem(struct array_container *s, int elemSub[], elemType b)
{
    int i, pos = 0, dim = s->dim;

    for(i = dim; i >= 2; i -- )
    {
        pos += pos * s->dimSize[i-2] + (elemSub[i-1]-1) * s->dimSize[i-2];
    }
    pos += elemSub[0]-1;

    s->data[pos] = b;
}

