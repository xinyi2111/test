#include<iostream>
using namespace std;

//struct Person
//{
//	char name[10];
//	int age;
//};

//int main()
//{
//	struct Person p = { "Three", 20 };
//	//c���Ժ�c++�ĶԱ�
//	//printf("%s\n,%d\n",p.name,p.age);
//	cout << "" << p.name << "\n" << "" << p.age << endl;
//    //����c���Ը����ã���Ϊ���Ͳ�ͬ
//	return 0;

//ȱʡ����
void TestFunc(int a = 0)
{
	cout << a << endl;
}

int main()
{
	TestFunc(5);
	TestFunc();

	return 0;
}