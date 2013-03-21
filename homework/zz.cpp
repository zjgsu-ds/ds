#include <stdio.h>
#include <malloc.h>
typedef struct node
/*单链表创建*/
{ 
	int data;
	struct node *link;
} NODE;
NODE *create()
{
	NODE *head,*tail,*p;
	int num;
	head=tail=NULL;
	printf("please input the numbers,-1 is the end\n");
	scanf("%d",&num);
	while(num!=-1)
	{
		p=(NODE*)malloc(sizeof(NODE));
		if(p==NULL)
		{
			printf("Malloc failure\n");
			return NULL;
		}

		p->data=num;
		p->link=NULL;
		if(head==NULL) head=p;
		else tail->link=p;
		tail=p;
		scanf("%d",&num);
	}
	return head;
}
/*比较数据大小*/
int compare(NODE*a,NODE*b)
{int c;

if(b->data>a->data)
a=a->link;
else { c=b->data;
return c;}

}

NODE *insert(NODE*head, int num)
{
	NODE *p,*q,*list;
	list=(NODE*)malloc(sizeof(NODE));
	list->data=num;
	list->link=NULL;
	p=head;q=NULL;
	while(p)
	{
		if(p->data<num)
		{
			q=p;p=p->link;
		}else
		{
			if(q)
			{
				q->link=list;
				list->link=p;
			}
			else {
				list->link=head;
				head=list;
			}
			break;
		}
	}
	if(!p)
		q->link=list;
	return head;
}

NODE*inverse(NODE *head)
{
	NODE *middle,*tail,*lead;
	tail=middle=NULL;lead=head;
	while(head)
	{
		middle=lead;
		lead=lead->link;
		middle->link=tail;
	}
	return middle;
}

 int printlist(NODE*head)
{while(head)
{
	printf("%6d",head->data);
	head=head->link;
}
return 0;}




int main()
{
NODE *m,*n,*a,*b, *l;
int c,d,num;
scanf("%d",&c);
a=create();
scanf("%d",&d);
b=create();
m=a;
n=b;
while(n!=NULL&&m!=NULL)
{num=compare(m,n);
l=insert(m,num);
m++;n++;
}

inverse(l);
printlist(l);
return 0;
}





