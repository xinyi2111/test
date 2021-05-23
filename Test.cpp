#include<iostream>
#include<string>
//#include<vld.h>
using namespace std;

class Base
{
public:
	virtual void f()
	{cout<<"Base::f()"<<endl;}
	virtual void h()
	{cout<<"Base::h()"<<endl;}
	virtual void g()
	{cout<<"Base::g()"<<endl;}
private:
	int m_a = 0;
	int m_b = 1;
};

class Base1
{
public:
	virtual void f()
	{cout<<"Base1::f()"<<endl;}
	virtual void h()
	{cout<<"Base1::h()"<<endl;}
	virtual void g()
	{cout<<"Base1::g()"<<endl;}
private:
	int m_a = 0;
	int m_b = 1;
};

class Base2
{
public:
	virtual void f()
	{cout<<"Base2::f()"<<endl;}
	virtual void h()
	{cout<<"Base2::h()"<<endl;}
	virtual void g()
	{cout<<"Base2::g()"<<endl;}
private:
	int m_a = 0;
	int m_b = 1;
};

class D : public Base, public Base1, public Base2
{
public:
	virtual void f()
	{cout<<"D::f()"<<endl;}
	virtual void h1()
	{cout<<"D::h()"<<endl;}
	virtual void g1()
	{cout<<"D::g()"<<endl;}
private:
	int m_c = 10;
};

void main()
{
	D d;
}

/*
typedef void (*VFPTR)();

void main()
{
	D  b;

	//int   *p = (int*)malloc(sizeof(int)*10);
	VFPTR *vtable = (VFPTR*)(*(int*)&b);

	for(int i=0; vtable[i]!=nullptr; ++i)  //NULL 0
		vtable[i]();
}

/*
void main()
{
	Base b;
	printf("b 对象的地址 = %p\n",&b);
	printf("虚表的地址 = %p\n",*(int *)(&b));

	((pFun)(*((int*)(*(int *)(&b)) + 0)))();
	((pFun)(*((int*)(*(int *)(&b)) + 1)))();
	((pFun)(*((int*)(*(int *)(&b)) + 2)))();
}

/*
class D : public Base
{
public:
	virtual  void show()
	{}
};


void main()
{
	Base b;
	D d;
}

/*
class A
{
public:
	virtual void Eat()
	{
		cout<<"A::Eat()"<<endl;
	}
	virtual void Foot()
	{
		cout<<"A::Foot()"<<endl;
	}
	virtual void Sleep()
	{
		cout<<"A::Sleep()"<<endl;
	}
};

class Person : public A
{
public:
	void Eat()
	{
		cout<<"Person::Eat()"<<endl;
	}
	void Foot()
	{
		cout<<"Person::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"Person::Sleep()"<<endl;
	}
};

class Dog : public A
{
public:
	void Eat()
	{
		cout<<"Dog ::Eat()"<<endl;
	}
	void Foot()
	{
		cout<<"Dog ::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"Dog ::Sleep()"<<endl;
	}
};

class N : public A
{
public:
	void Eat()
	{
		cout<<"N ::Eat()"<<endl;
	}
	void Foot()
	{
		cout<<"N ::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"N ::Sleep()"<<endl;
	}
};

//////////////////////////////////////////////
void Active(A *pa)
{
	pa->Eat();
	pa->Foot();
	pa->Sleep();
}


void main()
{
	A a;
}


/*
class Base
{
public:
	virtual void f(float x){ cout << "Base::f(float) " << x << endl; }
	void g(int a, int b){cout<<"Base::g(int,int)"<<endl;}
	void g(float x){ cout << "Base::g(float) " << x << endl; }
	void h(float x){ cout << "Base::h(float) " << x << endl; }
};

class Derived : public Base
{
public:
	virtual void f(float x){ cout << "Derived::f(float) " << x << endl; }
	void g(int x){ cout << "Derived::g(int) " << x << endl; }
	void h(float x){ cout << "Derived::h(float) " << x << endl; }
};

void main(void)
{
	Derived d;
	Base *pb = &d;
	Derived *pd = &d;

	pb->f(1.2);

	pb->g(3.14f); // Base::g(float) 3.14
	pd->g(3.14f); // Derived::g(int) 3	pd->f(2.3);

	pb->h(3.14f); // Base::h(float) 3.14 (surprise!)
	pd->h(3.14f); // Derived::h(float) 3.14

	pd->g(1,2);
}

/*
class Base
{
public:
	virtual void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
	virtual void fun(int a)
	{
		cout<<"Base::fun(int)"<<endl;
	}
	virtual void fun(int a, int b)
	{
		cout<<"Base::fun(int,int)"<<endl;
	}
};

class D : public Base
{
public:
	virtual void fun(int a,int b, int c)override
	{
		cout<<"D::fun()"<<endl;
	}
};

void main()
{
	D d;
	Base *pb = &d;
	pb->fun(1);
}

/*
class Base
{
public:
	virtual void fun()final
	{
		cout<<"Base::fun()"<<endl;
	}
	virtual void fun(int a)
	{
		cout<<"Base::fun(int)"<<endl;
	}
	virtual void fun(int a, int b)
	{
		cout<<"Base::fun(int,int)"<<endl;
	}
};

class D : public Base
{
public:
	virtual void fun(int a)
	{
		cout<<"D::fun()"<<endl;
	}
};

void main()
{
	D d;
	Base *pb = &d;
	pb->fun();
}

/*
class Base
{
public:
	Base()
	{
		//多态机制在构造函数中不发挥作用
		this->fun();
		cout<<"Base::Base()"<<endl;
	}
	virtual ~Base()
	{
		cout<<"Base::~Base()"<<endl;
	}
public:
	virtual Base& fun()
	{
		cout<<"Base::fun()"<<endl;
		return *this;
	}
	virtual void fun1()
	{
		//this->fun();  //Base *pb->fun()
		cout<<"Base::fun1()"<<endl;
	}
	virtual void fun2()
	{
		cout<<"Base::fun2()"<<endl;
	}
	void show()
	{
		cout<<"Base::show()"<<endl;
	}
private:
	//__vfptr: 8
	int m_a = 0; //4 + 4
};

class D : public Base
{
public:
	D()
	{
		cout<<"D::D()"<<endl;
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
	}
public:
	virtual D& fun()
	{
		cout<<"D::fun()"<<endl;
		return *this;
	}
	virtual void fun2()
	{
		cout<<"D::fun2()"<<endl;
	}
	virtual void print()
	{
		cout<<"D::print()"<<endl;
	}
	void show()
	{
		cout<<"D::show()"<<endl;
	}
};

void main()
{
	D d;
	//Base *pb = &d;
	//pb->fun1();

}

/*
void main()
{
	D d;
	Base *pb = &d;
	pb->fun();    //D
	//pb->fun1();
	//pb->print();
}

/*
void main()
{
	D d;
	Base *pb = &d;
	pb->fun();    //D

	pb->fun1();

	pb->show();
}

/*
class D : public Base
{
public:
	virtual void fun()
	{
		cout<<"D::fun()"<<endl;
	}
};

class C : public D
{
public:
	virtual void fun()
	{
		cout<<"C::fun()"<<endl;
	}
};

void main()
{
	C c;
	D *pd = &c;
	pd->fun();
}

/*
void main()
{
	D d;
	Base *pb = &d;
	pb->fun();  //多态

	Base &rb = d;
	rb.fun();

	Base b = d;
	b.fun();
}

/*
class A
{
public:
	virtual void Eat()
	{
		cout<<"A::Eat()"<<endl;
	}
	virtual void Foot()
	{
		cout<<"A::Foot()"<<endl;
	}
	virtual void Sleep()
	{
		cout<<"A::Sleep()"<<endl;
	}
};

class Person : public A
{
public:
	void Eat()
	{
		cout<<"Person::Eat()"<<endl;
	}
	void Foot()
	{
		cout<<"Person::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"Person::Sleep()"<<endl;
	}
};

class Dog : public A
{
public:
	void Eat()
	{
		cout<<"Dog ::Eat()"<<endl;
	}
	void Foot()
	{
		cout<<"Dog ::Foot()"<<endl;
	}
	void Sleep()
	{
		cout<<"Dog ::Sleep()"<<endl;
	}
};

//////////////////////////////////////////////
void Active(A *pa)
{
	pa->Eat();
	pa->Foot();
	pa->Sleep();
}

void main()
{
	Person p;
	Dog dog;

	Active(&p);
}


/*
class A
{};

class Dog : public A
{};

class Person : public A
{};

class Door
{};
class Whlee
{};

class Car 
{
private:
	Door d[4];   //组合
	Whlee w[5];
};

/*
class A
{
public:
	int m_a = 1;
};

class B :  virtual public A
{
public:
	int m_b = 2;
};

class C :  virtual public A
{
public:
	int m_c = 3;
};

class D : public B, public C
{
public:
	int m_d = 4;
};

void main()
{
	D d;

	B b = d;
	C c = d;
}

/*
void main()
{
	D d;
	cout<<d.m_d<<endl;
	cout<<d.m_b<<endl;
	cout<<d.m_c<<endl;
	//cout<<d.m_a<<endl;
	cout<<&d.B::m_a<<endl;
	cout<<&d.C::m_a<<endl;
}

/*
void main()
{
	D d;
	cout<<d.m_d<<endl;
	cout<<d.m_b<<endl;
	cout<<d.m_c<<endl;
	cout<<d.B::m_a<<endl;
	cout<<d.C::m_a<<endl;
	cout<<&d.B::m_a<<endl;
	cout<<&d.C::m_a<<endl;
}

/*
class Person
{
public:
	Person()
	{
		++_count;
	}
protected:
	string _name; // 姓名
public:
	static int _count; // 统计人的个数。
};
int Person::_count = 0;

class Student : public Person
{
protected:
	int _stuNum; // 学号
};
class Graduate : public Student
{
protected:
	string _seminarCourse; // 研究科目
};

void main()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate s4;
	//cout << " 人数 :" << Person::_count << endl;
	//Student::_count = 0;
	//cout << " 人数 :" << Person::_count << endl;
}

/*
class Student;
class Person
{
public:
	friend void Display(const Person& p, const Student &s);
private:
	string _name = "bite"; // 姓名
};

class Student : public Person
{
	friend void Display(const Person& p, const Student &s);
private:
	int _stuNum = 1000; // 学号
};

void Display(const Person& p, const Student &s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}

void main()
{
	Person p;
	Student s;
	Display(p, s);
}

/*
class Base
{
public:
	Base(int a):m_a(a)
	{
		m_x = new char[10];
		cout<<"Base::Base()"<<endl;
	}
	Base(const Base &b)
	{
		m_a = b.m_a;
		cout<<"Base::Base(const Base &b)"<<endl;
	}
	Base& operator=(const Base &d)
	{
		if(this != &d)
		{
			m_a = d.m_a;
			cout<<"Base& operator=(const Base &d)"<<endl;
		}
		return *this;
	}
	~Base()
	{
		delete []m_x;
		cout<<"Base::~Base()"<<endl;
	}
public:
	void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
	void fun(int)
	{
		cout<<"Base::fun(int)"<<endl;
	}
	void fun(int a, int b)
	{
		cout<<"Base::fun2(int,int)"<<endl;
	}
private:
	int m_a = 0;
	char *m_x;
};

class D : public Base
{
public:
	D(int d) : Base(d)
	{
		m_y = new char[100];
		m_d = d;
		cout<<"D::D()"<<endl;
	}
	D(const D &d):Base(d)
	{
		m_d = d.m_d;
		cout<<"D::D(const D &d)"<<endl;
	}
	D& operator=(const D &d)
	{
		if(this != &d)
		{
			Base::operator=(d);
			m_d = d.m_d;
			cout<<"D& operator=(const D &d)"<<endl;
		}
		return *this;
	}
	~D()
	{
		delete []m_y;
		cout<<"D::~D()"<<endl;
	}
public:
	void list()
	{
		fun();
		//fun1();
		//fun2();
	}
	void fun()
	{
		cout<<"D::fun()"<<endl;
	}
	void fun(int )
	{
		cout<<"D::fun(int)"<<endl;
	}
private:
	int m_d = 1;
	char *m_y;
};

void main()
{
	D *pd = new D(1);
	delete pd;
}

/*
void main()
{
	D *pd = new D(1);
	delete pd;
}

/*
void main()
{
	D d(1);
	D d1 = d;
	D d2(0);
	d2 = d1;
}
/*
void main()
{
	D d;
	Base *pb = &d;
	pb->fun();
	pb->fun(1);
	pb->list();
}

/*
void main()
{
	//赋值兼容规则
	D d;
	Base b;

	b = d;
	Base *pb = &d;
	Base &rb = d;
}

/*
void main()
{
	D d;
	d.fun();
	d.fun(1);
	d.Base::fun(1,2);
}


/*
class Base
{
public:
	Base()
	{
		cout<<"Base::Base()"<<endl;
	}
	~Base()
	{
		cout<<"Base::~Base()"<<endl;
	}
public:
	void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
protected:
	void fun1()
	{
		cout<<"Base::fun1()"<<endl;
	}
private:
	void fun2()
	{
		cout<<"Base::fun2()"<<endl;
	}
private:
	int m_a = 0;
};

class D : public Base
{
public:
	D()
	{
		cout<<"D::D()"<<endl;
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
	}
public:
	void list()
	{
		fun();
		fun1();
		//fun2();
	}
private:
	int m_d = 1;
};

void main()
{
	D d;
	d.fun();
	//d.fun1();
	//d.fun2();
}

/*
void main()
{
	D d;
	cout<<sizeof(d)<<endl;
}
*/