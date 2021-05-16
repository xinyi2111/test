#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define MAX_SIZE 90

typedef int key_type;          
typedef char info_type;
typedef struct node {           
	key_type key;               // 关键字项
	info_type data;             // 其他数据域
	struct node *lchild;        // 左孩子指针
	struct node *rchild;        // 右孩子指针
}BSTNode;

/*----------------以括号表示法输出二叉排序树bt------------------*/
void disp_bst(BSTNode *bt);         // 函数声明

bool insert_bst(BSTNode *&bt, key_type key) // 在以bt为根结点的BST中插入一个关键字为key的结点
{
	if (bt == NULL)      // 原树为空,新插入的记录为根结点
	{
		bt = (BSTNode *)malloc(sizeof(BSTNode));
		bt->key = key;
		bt->lchild = bt->rchild = NULL;
		return true;
	}
	else if (key == bt->key)
		return false;
	else if (key < bt->key)
		return insert_bst(bt->lchild, key);     // 插入到bt结点的左子树中
	else
		return insert_bst(bt->rchild, key);     // 插入到bt结点的右子树中
}

/*----------------由数组a中的关键字建立一颗二叉排序树------------------*/
BSTNode *create_bst(key_type a[], int n)
{
	BSTNode *bt = NULL;         // 初始时bt为空树
	int i = 0;

	while (i < n)
	{
		if (insert_bst(bt, a[i]) == 1)       // 将a[i]插入二叉排序树bst中
		{
			disp_bst(bt);
			i++;
		}
	}

	return bt;
}


/*----------------以括号表示法输出二叉排序树bt------------------*/
void disp_bst(BSTNode *bt)
{
	if (bt != NULL)
	{
		if (bt->lchild != NULL || bt->rchild != NULL)
		{
         //  有孩子结点时才输出(
			disp_bst(bt->lchild);       //  递归处理左子树
			if (bt->rchild != NULL)
          //  有右孩子结点时才输出,
			disp_bst(bt->rchild);       //  递归处理右子树
             //  有孩子结点时才输出)
		}
	}
}

key_type predt = -32767;                            

bool judge_bst(BSTNode *bt)
{
	bool b1, b2;

	if (bt == NULL)
		return true;
	else
	{
		b1 = judge_bst(bt->lchild);
		if (b1 == false || predt >= bt->key)
			return false;
		b2 = judge_bst(bt->rchild);
		return b2;
	}
}



void search_bst1(BSTNode *bt, key_type key, key_type path[], int i)
{
	int j;

	if (bt == NULL)
		return;
	else if (key == bt->key) 
	{
		path[i + 1] = bt->key; 
		for (j = 0; j <= i + 1; j++)
		{
			printf("%3d", path[j]);
		}
	}
	else
	{
		path[i + 1] = bt->key;
		if (key < bt->key)
			search_bst1(bt->lchild, key, path, i + 1);     
		else
			search_bst1(bt->rchild, key, path, i + 1);     
	}
}

int search_bst2(BSTNode *bt, key_type key)
{
	if (bt == NULL)
		return 0;
	else if (key == bt->key)               
	{
		printf("%3d", bt->key);         
		return 1;
	}
	else if (key < bt->key)
	{
		search_bst2(bt->lchild, key);       
	}
	else
	{
		search_bst2(bt->rchild, key);     
	}
	printf("%3d", bt->key);               
}


void delete_node1(BSTNode *p, BSTNode *&r)    
{
	BSTNode *q;

	if (r->rchild != NULL)                      
	{
		delete_node1(p, r->rchild);
	}
	else                                       
	{
		p->key = r->key;                        
		p->data = r->data;
		q = r;                                
		r = r->lchild;                          
		free(q);                               
	}
}


void delete_node(BSTNode *&p)
{
	BSTNode *q;

	if (p->rchild == NULL)           
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else if (p->lchild == NULL)                        
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else
		delete_node1(p, p->lchild);                    
}

bool delete_bst(BSTNode *&bt, key_type key)
{
	if (bt == NULL)                            
		return false;
	else
	{
		if (key < bt->key)
			return delete_bst(bt->lchild, key);        
		else if (key > bt->key)
			return delete_bst(bt->rchild, key);      
		else                                           
		{
			delete_node(bt);                          
			return true;
		}
	}
}
static BSTNode *lca(BSTNode *bt, key_type x, key_type y)
{
	if (bt == NULL)
		return NULL;

	if (x < bt->key && y < bt->key)
		return lca(bt->lchild, x, y);
	else if (x > bt->key && y > bt->key)
		return lca(bt->rchild, x, y);
	else
		return bt;
}

int main(int argc, char *argv[])
{
	BSTNode *bt, *p;
	key_type x = 1, y = 4;
	key_type a[] = { 5, 2, 1, 6, 7, 4, 8, 3, 9 };
	key_type n = 9;

	bt = create_bst(a, n);                            
	disp_bst(bt);
	if (p = lca(bt, x, y))
		printf("最近公共祖先:%d\n", p->key);


	return 0;
}

