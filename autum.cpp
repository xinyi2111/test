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
//	//c语言和c++的对比
//	//printf("%s\n,%d\n",p.name,p.age);
//	cout << "" << p.name << "\n" << "" << p.age << endl;
//    //这里c语言更好用，因为类型不同
//	return 0;

//缺省参数
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