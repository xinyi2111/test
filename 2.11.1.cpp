#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
 
typedef struct Node
{
	int data;
	struct Node*next;
}Node,*List;
 
void InitList(List plist)
{
	assert(plist != NULL);
	plist->next = NULL;
}
 
bool Insert_tail(List plist,int val)
{
    //第一步，创建新节点
    Node *p = (Node *)malloc(sizeof(Node));
    assert(p != NULL);
    if(p == NULL)
	return false;
    p->data = val;
    //第二步，找尾节点
    Node *q;
    for(q=plist;q->next!=NULL;q=q->next)
	;
    //将p插入在q的后面
    p->next = q->next;//p->next = NULL;
    q->next = p;
 
    return true;
}
 
void Merge(List plistC,List plistA,List plistB)
{
	Node *s = plistA->next;
    Node *q = plistB->next;
	while(plistB->next != NULL&&plistA->next != NULL)
	{
		s = plistA->next;
		q = plistB->next;
		if(s->data <= q->data)
		{
			plistA->next = s->next;
			s->next = NULL;
			s->next = plistC->next;
			plistC->next = s;
		}
		else
		{
			plistB->next = q->next;
			q->next = NULL;
			q->next = plistC->next;
			plistC->next = q;
		}
	}
	if(plistA->next == NULL)
	{
		
		while(plistB->next != NULL)
		{
			q = plistB->next;
			plistB->next = q->next;
			q->next = plistC->next;
			plistC->next = q;
		}
	}
	else
	{
		
		while(plistA->next != NULL)
		{
			s = plistA->next;
			plistA->next = s->next;
			s->next = plistC->next;
			plistC->next = s;
		}
	}
 
}
 
void Show(List plist)
{
	for(Node *p=plist->next;p!= NULL;p=p->next)
	{
		printf("%d ",p->data);
	}
	printf("\n");
}
 
void Destroy(List plist)
{
	assert(plist != NULL);
    Node *p;
    while(plist->next != NULL)
    {
	p = plist->next;
	plist->next = p->next;
	}
	free(p);
}
 
int main()
{
    Node head1;
    Node head2;
	Node head3;
    InitList(&head1);
    InitList(&head2);
	InitList(&head3);
    int i;
    for(i=0;i<5;i++)
    {
	Insert_tail(&head1,i);
    }
    for(i=3;i<8;i++)
    {
	Insert_tail(&head2,i);
    }
    Show(&head1);
	Show(&head2);
	Merge(&head3,&head1,&head2);
	Show(&head3);
	Destroy(&head3);
    return 0;
}
 


