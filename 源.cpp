#include<iostream>
#include<vector>
#include<stack>
#include<assert.h>
using namespace std;

//AVL
template<class Type>
class AVLTree;

//节点类
template<class Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode() :data(Type()), leftChild(nullptr), rightChild(nullptr), bf(0)
	{}
	AVLNode(Type d) :data(d), leftChild(nullptr), rightChild(nullptr), bf(0)
	{}
	~AVLNode()
	{}
private:
	Type data;
	AVLNode *leftChild;
	AVLNode *rightChild;
	int bf;  //平衡因子 0 -1 1  2 -2
};

template<class Type>
class AVLTree
{
public:
	AVLTree() : root(nullptr)
	{}
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
	bool Remove(const Type &key)
	{
		return Remove(root, key);
	}
protected:
	bool Insert(AVLNode<Type> *&t, const Type &x);
	bool Remove(AVLNode<Type> *&t, const Type &key);
protected:
	void RotateR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subR = ptr;
		ptr = subR->leftChild;
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		ptr->bf = subR->bf = 0;
	}
	void RotateL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		ptr = subL->rightChild;
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		ptr->bf = subL->bf = 0;
	}
	void RotateLR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subR = ptr;
		AVLNode<Type> *subL = ptr->leftChild;
		ptr = subL->rightChild;

		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//subL->bf
		if (ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;

		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//subR->bf;
		if (ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;

		ptr->bf = 0;
	}
	void RotateRL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		AVLNode<Type> *subR = ptr->rightChild;
		ptr = subR->leftChild;

		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//subR->bf
		if (ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;

		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//subL->bf
		if (ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;

		ptr->bf = 0;
	}
private:
	AVLNode<Type> *root;
};