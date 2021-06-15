#include<iostream>
#include<vector>
using namespace std;

typedef enum{RED = 0, BLACK=1}Color_Type;

template<class Type>
class RBTree;
//红黑树
template<class Type>
class RBNode
{
	friend class RBTree<Type>;
public:
	RBNode(Type d):data(d), leftChild(nullptr), rightChild(nullptr),parent(nullptr),color(RED)
	{}
	~RBNode()
	{}
private:
	Type data;
	RBNode *leftChild;
	RBNode *rightChild;
	RBNode *parent;
	Color_Type color;
};

template<class Type>
class RBTree
{
public:
	RBTree() :root(Nil), Nil(_Buynode())
	{
		Nil->leftChild = Nil->rightChild = Nil->parent = nullptr;
		Nil->color = BLACK;
	}
public:
	//bool Insert(const Type &x)
	//{
	//	return Insert(root, x);
	//}
	bool Remove(const Type &key)
	{
		return Remove(root, key);
	}
protected:
	/*bool Insert(RBNode<Type> *&t, const Type &x);*/
	bool Remove(RBNode<Type> *&t, const Type &key);
	RBNode<Type>* _Buynode(const Type &x = Type())
	{
		RBNode<Type> *s = new RBNode<Type>(x);
		s->leftChild = s->rightChild = s->parent = Nil;
		return s;
	}
protected:
	/*void Insert_Fixup(RBNode<Type> *&t, RBNode<Type> *x);*/
	void Remove_Fixup(RBNode<Type> *&t, RBNode<Type> *x);
protected:
	void RotateRight(RBNode<Type> *&t, RBNode<Type> *x)//右转方法
	{
		RBNode<Type> *y = x->leftChild;
		x->leftChild = y->rightChild;
		if(y->rightChild != Nil)
			y->rightChild->parent = x;

		y->rightChild = x;
		if(x == t)
			t = y;
		else if(x == x->parent->leftChild)
			x->parent->leftChild = y;
		else
			x->parent->rightChild = y;

		y->parent = x->parent;
		x->parent = y;
	}
	void RotateLeft(RBNode<Type> *&t, RBNode<Type> *x)//左转方法
	{
		RBNode<Type> *y = x->rightChild;
		x->rightChild = y->leftChild;
		if(y->leftChild != Nil)
			y->leftChild->parent = x;

		y->leftChild = x;
		if(x == t)
			t = y;
		else if(x == x->parent->leftChild)
			x->parent->leftChild = y;
		else
			x->parent->rightChild = y;

		y->parent = x->parent;
		x->parent = y;
	}
private:
	RBNode<Type> *Nil;
	RBNode<Type> *root;
};

//template<class Type>
//bool RBTree<Type>::Insert(RBNode<Type> *&t, const Type &x)
//{
//	//1 按照bst进行节点插入
//	RBNode<Type> *pr = Nil;
//	RBNode<Type> *p = t;
//	while(p != Nil)
//	{
//		if(x == p->data)
//			return false;
//
//		pr = p;
//
//		if(x < p->data)
//			p = p->leftChild;
//		else
//			p = p->rightChild;
//	}
//
//	p = _Buynode(x);
//
//	if(pr == Nil)
//		t = p;
//	else
//	{
//		if(x < pr->data)
//			pr->leftChild = p;
//		else
//			pr->rightChild = p;
//		p->parent = pr;
//	}
//
//	//2 调整平衡
//	Insert_Fixup(t, p);
//
//	return true;
//}
//
//template<class Type>
//void RBTree<Type>::Insert_Fixup(RBNode<Type> *&t, RBNode<Type> *x)
//{
//	while(x->parent->color == RED)
//	{
//		RBNode<Type> *s;
//		if(x->parent == x->parent->parent->leftChild) 
//		{
//			//左分支
//			s = x->parent->parent->rightChild;
//
//			if(s->color == RED)
//			{
//				//状况三
//				x->parent->color = BLACK;
//				s->color = BLACK;
//				x->parent->parent->color = RED;
//				x = x->parent->parent;
//			}
//			else
//			{
//				if(x == x->parent->rightChild)
//				{
//					//状况二
//					x = x->parent;
//					RotateLeft(t, x);
//				}
//				//状况一
//				x->parent->color = BLACK;
//				x->parent->parent->color = RED;
//				RotateRight(t, x->parent->parent);
//			}
//		}
//		else
//		{
//			//右分支
//			s = x->parent->parent->leftChild;
//			if(s->color == RED)
//			{
//				//状况三
//				x->parent->color = BLACK;
//				s->color = BLACK;
//				x->parent->parent->color = RED;
//				x = x->parent->parent;
//			}
//			else
//			{
//				if(x == x->parent->leftChild)
//				{
//					//状况二
//					x = x->parent;
//					RotateRight(t, x);
//				}
//				//状况一
//				x->parent->color = BLACK;
//				x->parent->parent->color = RED;
//				RotateLeft(t, x->parent->parent);
//			}
//		}
//	}
//	t->color = BLACK;
//}

template<class Type>
bool RBTree<Type>::Remove(RBNode<Type> *&t, const Type &key)
{
	//1 按照BST的规则删除节点
	RBNode<Type> *p = t, *q;
	while(p != Nil)//查找节点
	{
		if(key == p->data)
			break;
		if(key < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	if(p == Nil)//要查找的节点不存在
		return false;

	if(p->leftChild!=Nil && p->rightChild!=Nil)//要删除的节点有左右子树
	{
		q = p->leftChild;//寻找前驱
		while(q->rightChild != Nil)
			q = q->rightChild;

		p->data = q->data;
		p = q;
	}

	if(p->leftChild != Nil)
		q = p->leftChild;
	else
		q = p->rightChild;


	if(p == p->parent->leftChild)
		p->parent->leftChild = q;
	else
		p->parent->rightChild = q;

	//if(q != Nil)
	q->parent = p->parent;

	//2 调整平衡
	if(p->color == BLACK)
		Remove_Fixup(t, q);

	//删除节点
	delete p;
	return true;
}

template<class Type>
void RBTree<Type>::Remove_Fixup(RBNode<Type> *&t, RBNode<Type> *x)//删除完节点调整平衡
{
	RBNode<Type> *w; //兄弟节点
	while(x!=t && x->color==BLACK)
	{
		if(x == x->parent->leftChild) 
		{
			//删除的节点在左分支
			w = x->parent->rightChild;

			//情形四
			if(w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				RotateLeft(t, x->parent);
				w = x->parent->rightChild;
			}
			//情形三
			if(w->leftChild==Nil && w->rightChild==Nil)
			{
				x->parent->color = BLACK;
				w->color = RED;
				x = x->parent;
			}
			else
			{
				//情形二
				if(w->leftChild != Nil)
				{
					w->color = RED;
					w->leftChild->color = BLACK;
					w = w->leftChild;
					RotateRight(t, w->parent);
				}
				//情形一
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->rightChild->color = BLACK;
				RotateLeft(t, x->parent);
				x = t;
			}
		}
		else
		{
			//删除的节点在右分支
			w = x->parent->leftChild;

			//情形四
			if(w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				RotateRight(t, x->parent);
				w = x->parent->leftChild;
			}

			//情形三
			if(w->leftChild==Nil && w->rightChild==Nil)
			{
				w->color = RED;
				x->parent->color = BLACK;
				x = x->parent;
			}
			else
			{
				//情形二
				if (w->rightChild != Nil)
				{
					w->color = RED;
					w->rightChild->color = BLACK;
					w = w->rightChild;
					RotateLeft(t, w->parent);
				}
				//情形一
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->leftChild->color = BLACK;
				RotateRight(t, x->parent);
				x = t;
			}
		}
	}
	x->color = BLACK;//被删除的节点只有一个红色子节点
}

void main()
{
	vector<int> iv = {10, 7, 8, 15, 5, 6, 11, 13, 12}; 
	RBTree<int> rb;

	for(const auto &e : iv)
		rb.Insert(e);

	rb.Remove(5);
	rb.Remove(7);
	rb.Remove(6);

	return;
}