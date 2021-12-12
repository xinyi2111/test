#include<stdio.h>
//枚举关键——enum

int main()
{
	char arr1[] = "abc";
	char arr2[] = {'a','b','c',0};//'\0'也是字符，是字符串结束的标志，不过'\0'本身的值就是0
	printf("%s\n", arr2);
	printf("%s\n", arr1);

	return 0;
}
//enum Sex
//{
//	MALE,//这些是枚举常量
//	FEMALE,
//	SECRET
//};
//int main()
//{
//	enum Sex s = MALE;
//	s = FEMALE;
//	printf("%d\n",s);
//	printf("%d\n", MALE);//0
//	printf("%d\n",FEMALE);//1
//	printf("%d\n", SECRET);//2
//}

////#define 定义的标识符常量
//#define MAX 10
//int main()
//{
//	const int sr = 5;
//	printf("%d",sr);
//	//sr = 6;//本质还是变量，只不过具有常属性
//	//printf("%d", sr);
//	return 0;
//}