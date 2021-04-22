#include<iostream>
using namespace std;

class Complex
{
	friend Complex operator+(const Complex &c1, const Complex &c2);
	friend Complex operator+(int value, const Complex &c2);
	friend ostream& operator<<(ostream &out, const Complex &c);
	//friend����Ҫ����߲��Ƕ���ֻ�ܵ���youyuan
	//youyuan��һ����Ҫ����������
public:
	Complex(int real = 0, int imag = 0) :m_real(real), m_imag(imag)//ʵ�����鲿
	{	}
	~Complex()
	{}//��������Ҫϰ�߱����
public:
	Complex operator+(const Complex &c)//��Ա����������ϰ���Ե�����һ�����ٵ��Ǹ�ͨ��this����
	{
		Complex tmp(m_real + c.m_real, m_imag + c.m_imag);
		return tmp;
	}
	Complex operator+(int value)//����
	{
		Complex tmp(m_real + value, m_imag + value);
		return tmp;
	}

private:
	int m_real;
	int m_imag;
};

Complex /*Complex::���ǳ�Ա��youyuan���Բ��ü�������*/ operator+(const Complex &c1, const Complex &c2)
{
	//û��thisָ�����Բ�����������ʵ������ĸ���
	Complex tmp(c1.m_real + c2.m_real, c1.m_imag + c2.m_imag);
	return tmp;
}
Complex /*Complex::���ǳ�Ա��youyuan���Բ��ü�������*/ operator+(int value , const Complex &c2)
{
	Complex tmp(value + c2.m_real, value + c2.m_imag);
	return tmp;
}
ostream& operator<<(ostream &out, const Complex &c)
{
	out << "(" << c.m_real << "," << c.m_imag << ")" << endl;
	return out;//�����ſ���������� 
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
	c = c1 + 10;//10��Ӧvalue
	c = 10 + c1;//�����ԣ���Ϊ10���Ƕ���
	//���ڿ�������Ϊ������youyuan����
	cout << c << endl;
	operator<<(cout, c);
}






class Int//������������������й�
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
		//operator+��&a,b)a����thisָ�룬��Ա������Ҫ����������
		Int tmp(i.m_i + m_i);
		return tmp;

	} 
public://+=����
	Int& operator+=(const Int &i)
	{
		this->m_i += m_i;//this->����ʡ��
		return *this;//���ص�ǰ�����ֵ
	}

public://==����
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
		m_i++;*///����ȡ����Ϊreturn*thisֱ�ӷ��أ����޷�����++����
		Int tmp(*this);//��++i��Ȳ������÷��أ���Ҫ���ÿ������캯����Ч�ʸ���
		m_i++;
		return tmp;//����������ʱ����
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
	//int a;//����
	//Int a;//����
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
public://����Ĭ�Ϻ����Լ���������س���
	//�����б�ĳ�ʼ��
	Test(int data = 0) : m_data(data)//���캯��Ҳ��������ת��������
	//Test(int data=0) ��m_data(0)�͸����������������Ҳ���ǰ�һ������ ת�������Ӧ�Ķ���
	{
		//m_data == data;
	}
	Test(const Test &t)//�������캯��
	{
		this->m_data = t.m_data;//this->����ʡ�ԣ�ָ��ǰ����
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
//	Test operator+(const Test &t)//ֻҪ�в������Ϳ��ԣ���Ӱ�캯������
//	{
//		Test tmp(t.m_data + m_data);//���ݿ��Բ��üӺ��뺯����ͳһ�����ǿ����ǿ��ԣ�����û�б�Ҫ
//		return tmp;
//	}
//
//
//
public://����ʵ��
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
//	//Test t1(t);//û�п������캯��������������˵����Ĭ�ϣ�
//	//Test t1 = t;//��ʼ��
//	//Test t2;
//	//t2 = t1;//��ֵ
//	//Test *pt = &t;//ȡ��ַ(��Ŀ��
//	//const Test t3(100);
//	////Test *pt2 = &t3;//�����
//	//const Test *pt2 = &t3;//���ᾭ����һ��ȡ��ַ����,����õڶ���
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
		
		t = 100;//���캯����������ת��������
		t = (Test)100;//����ͬ���Ͳſ��Ը�ֵ
		int value = t;//���͵�����
	}
