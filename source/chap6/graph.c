
#include "stdio.h"
#include "stdlib.h"

struct graph_container
{
	char *pVertex;
	float *pEdge;
	int n;
};

void InitGraph(struct graph_container *pGraph);
void CreateGraph(struct graph_container *pGraph);
int VertexDegree(struct graph_container *pGraph, int i);
int GraphEdgeNumber(struct graph_container *pGraph);

void main()
{
	// һ��ͼ����
	struct graph_container g;

	int iV = 1;

	// ��ʼ��������
	InitGraph(&g);

	// ����һ��ͼ:����ͼ�ṹ�����ݷ���������
	CreateGraph(&g);

	// ���һ������Ķ�
	printf("The degree of vertex %d is: %d\n", iV, VertexDegree(&g, iV));
	
	// ��ͼ�бߵ�����
	printf("The number of graph edges is: %d\n", GraphEdgeNumber(&g));

	return;
}

void InitGraph(struct graph_container *pGraph)
{
	pGraph->pVertex = 0;
	pGraph->pEdge = 0;
	pGraph->n = 0;
}

void CreateGraph(struct graph_container *pGraph)
{
	int i, j, k, e, n;
	float w;
	
	// ����ͼ�ж������ͱ���
	scanf("%d%d", &n, &e); 

	// ����ͼ�����ݴ洢�ռ�
	pGraph->n = n;
	pGraph->pVertex = (char *)malloc(sizeof(char)*n);
	pGraph->pEdge = (float *)malloc(sizeof(float)*n*n);

	// ��ʼ���ڽӾ���
	for(i = 0; i < n; i ++)
		for(j = 0; j < n; j ++)
			pGraph->pEdge[i*n+j] = 0;

	// ���붥������
	for(i = 0; i < n; i ++)
		pGraph->pVertex[i] = getchar();
	
	// ����߻���Ȩֵ
	for(k = 0; k < e; k ++)
	{
		scanf("%d%d%f", &i, &j, &w);
		pGraph->pEdge[i*n+j] = w;
	}
}

int VertexDegree(struct graph_container *pGraph, int i)
{
	int degree = 0, k;

	for(k = 0; k < pGraph->n; k ++)
	{
		if(pGraph->pEdge[(i-1)*pGraph->n + k] != 0)
		{
			degree ++;
		}
	}

	return degree;
}

int GraphEdgeNumber(struct graph_container *pGraph)
{
	int e = 0, i;

	for(i = 0; i < pGraph->n*pGraph->n; i ++)
	{
		if(pGraph->pEdge[i] != 0)
		{
			e ++;
		}
	}

	return e/2;
}

