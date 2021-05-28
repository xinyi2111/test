#include "SList.h"

void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("malloc node fail\n");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListPushBack(SListNode** pphead, SLTDataType x)
{
	SListNode* newnode = BuySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		// ��β
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SListNode** pphead, SLTDataType x)
{
	SListNode* newnode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}

void SListPopBack(SListNode** pphead)
{
	// 1.��
	// 2.һ���ڵ�
	// 3.����ڵ�
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);

		*pphead = next;
	}
}
