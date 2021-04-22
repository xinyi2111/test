#include<iostream>
using namespace std;

class Complex
{
	friend Complex operator+(const Complex &c1, const Complex &c2);
	friend Complex operator+(int value, const Complex &c2);
	friend ostream& operator<<(ostream &out, const Complex &c);
	//friend很重要，左边不是对象只能调用youyuan
	//youyuan不一定需要对象来调动
public:
	Complex(int real = 0, int imag = 0) :m_real(real), m_imag(imag)//实部，虚部
	{	}
	~Complex()
	{}//析构函数要习惯标出来
public:
	Complex operator+(const Complex &c)//成员方法参数比习惯性的少了一个，少的那个通过this传递
	{
		Complex tmp(m_real + c.m_real, m_imag + c.m_imag);
		return tmp;
	}
	Complex operator+(int value)//重载
	{
		Complex tmp(m_real + value, m_imag + value);
		return tmp;
	}

private:
	int m_real;
	int m_imag;
};

Complex /*Complex::不是成员是youyuan所以不用加作用域*/ operator+(const Complex &c1, const Complex &c2)
{
	//没有this指针所以参数个数是真实运算符的个数
	Complex tmp(c1.m_real + c2.m_real, c1.m_imag + c2.m_imag);
	return tmp;
}
Complex /*Complex::不是成员是youyuan所以不用加作用域*/ operator+(int value , const Complex &c2)
{
	Complex tmp(value + c2.m_real, value + c2.m_imag);
	return tmp;
}
ostream& operator<<(ostream &out, const Complex &c)
{
	out << "(" << c.m_real << "," << c.m_imag << ")" << endl;
	return out;//有它才可以链等输出 
}


void main()
{
	Test t(100);
	fun(t);
}

void main()
{
	Complex c1(1, 2);
	Complex c2(3, 4);
	Complex c;
	c = c1 + 10;//10对应value
	c = 10 + c1;//不可以，因为10不是对象
	//现在可以是因为调用了youyuan方法
	cout << c << endl;
	operator<<(cout, c);
}






class Int//内容是与运算符重载有关
{
	friend ostream& operator<<(ostream &out, const Int  &i);
public:
	Int(int i = 0) :m_i(i)
	{
		//m_i == i;
	}
	Int operator+(const Int &i)
	{
		//a+b
		//a.operator+(b)
		//operator+（&a,b)a传给this指针，成员方法需要对象来驱动
		Int tmp(i.m_i + m_i);
		return tmp;

	} 
public://+=重载
	Int& operator+=(const Int &i)
	{
		this->m_i += m_i;//this->可以省略
		return *this;//返回当前对象的值
	}

public://==重载
	bool operator==(const Int &i)
	{
		return m_i == i.m_i;
	}
	bool operator!=(const Int &i)
	{
		//return m_i != i.m_i;
		return !(*this == i);
	}
public:
	bool operator>(const Int &i)
	{
		return m_i > i.m_i;
	}
	bool operator<(const Int &i)
	{
		return m_i < i.m_i;
	}
public:
	Int& operator++()//++i
	{
		m_i++;
		return *this;
	}
	Int operator++(int)//i++
	{
		/*return *this;
		m_i++;*///不可取，因为return*this直接返回，再无法进行++操作
		Int tmp(*this);//与++i相比不能引用返回，还要调用拷贝构造函数，效率更低
		m_i++;
		return tmp;//还创建了临时对象
	}
	
	

	
private:
	int m_i;
};

 ostream& operator<<(ostream &out, const Int &i)
{
	out << i.m_i;
	return out;
}
void main()
{
	//int a;//变量
	//Int a;//对象
	Int a1;
	Int a2;
	Int a = a1 + a2;
	a += a1;
	cout << "t1=" << a << endl;
	if (a == a1)
		cout << "a==a1" << endl;
	else if (a > a1)
		cout << "a>a1" << endl;
	else if (a < a1)
		cout << "a<a1" << endl;
	else if (a != a1)
		cout << "a!=a1" << endl;
	Int b = 1;
	Int c = 1;
	Int b1 = ++b;
	Int c1 = c++;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	cout << "b1=" << b1 << endl;
	cout << "c1=" << c1 << endl;
}







class Test
{
	friend void fun(Test &t);
    friend ostream& operator<<(ostream &out, const Test &t);
public://六个默认函数以及运算符重载初阶
	//参数列表的初始化
	Test(int data = 0) : m_data(data)//构造函数也起到了类型转换的作用
	//Test(int data=0) ：m_data(0)就给不出来上面的作用也就是把一个整数 转换成相对应的对象
	{
		//m_data == data;
	}
	Test(const Test &t)//拷贝构造函数
	{
		this->m_data = t.m_data;//this->可以省略，指向当前对象。
	}
	Test& operator=(const Test &t)
	{
		if (this != &t )
		{
			m_data = t.m_data;
		}
		return *this;
	}
//public:
//	Test Add(const Test &t)
//	{
//		Test tmp(t.m_data + m_data);
//		return tmp;
//	}
//	Test operator+(const Test &t)//只要有操作符就可以，不影响函数内容
//	{
//		Test tmp(t.m_data + m_data);//内容可以不用加号与函数名统一，但是可以是可以，就是没有必要
//		return tmp;
//	}
//
//
//
public://函数实现
	//Test* operator&()
	//{
	//	return this;
	//}
	//const Test* operator&()const 
	//{
	//	return this;
	//}
	int GetData()const
	{
		return m_data;
	}
public:
	operator int()
	{
		return m_data;
	}


private:
	int m_data;

};
Test fun(const Test &t)
{
	int value = t.GetData();
	return Test(value);
}
//void fun(Test &t)
//{
//	int value = t.m_data;
//	cout << "value=" << value;
//}
void main()
{
	Test a(1);
	//Test b = fun(a);
}
//
// ostream& operator<<(ostream &out, const Test &t)
//{
//	out<<t.m_data;
//	return out;
//}
//
//void main()
//{
//	Test t1(29);
//	cout << "t1=" << t1.GetData() << endl;
//	cout << "t1=" << t1 << endl;
//
//}
//void main()
//{
//	//Test t(10);
//	//Test t1(t);//没有拷贝构造函数照样可以运行说明有默认；
//	//Test t1 = t;//初始化
//	//Test t2;
//	//t2 = t1;//赋值
//	//Test *pt = &t;//取地址(单目）
//	//const Test t3(100);
//	////Test *pt2 = &t3;//会出错
//	//const Test *pt2 = &t3;//不会经过第一个取地址函数,会调用第二个
//	Test t1(19);
//	Test t2(20);
//	Test t3;
//	//t3 = t1.Add(t2);
//	t3 = t1 + t2;
//	
//	cout << "t3=" << t3 << endl;
//}
	void main()
	{        
		Test t;
		
		t = 100;//构造函数起到了类型转换的作用
		t = (Test)100;//左右同类型才可以赋值
		int value = t;//类型的重载
	}
