#include<iostream>
using namespace std;
//这里将要实现继承的一些例子
class Father
{

public:



private:

protected:


};


class Son
{
public:


private:


protected:


};


void main()
{

}

//抽象类（不能实例化对象）
class Hy
{
public:
	virtual void sleep() = 0;//纯虚函数 作为接口提供给子类
	//为了 实现多态
	//虚表在运行期间动态生成
	//虚基类优先构造,再是普通的父类
	//父类的指针调用虚函数体现了gala的厉害
	//函数的默认值不会改变 
	//cryin


};