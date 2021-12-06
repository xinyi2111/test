//#include<stdio.h>
//int main()
//{
//	int a = 4;
//	printf("%d\n", ++a);//前置++先使用，后打印
//	printf("%d\n", a++);//后置++
//	int b = (int)2.14;
//	return 0;
//}

//#include<stdio.h>
//
//void test1(int arr1[])
//{
//	printf("%d\n", sizeof(arr1));
//}
//void test2(char arr2[])
//{
//	printf("%d\n", sizeof(arr2));
//
//}
//int main()
//{
//	int arr1[10] = { 0 };
//	char arr2[10] = { 0 };
//	printf("%d\n", sizeof(arr1));
//	printf("%d\n", sizeof(arr2));
//	test1(arr1);
//	test2(arr2);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	printf("%d %d %d %d ", a, b, c, d);
//	return 0;
//	//int i = 0, a = 1, b = 2, c = 3, d = 4;
//	//i = a++ && ++b && d++;
//	//printf("%d %d %d %d ", a, b, c, d);
//	//return 0;
//	//int i = 0, a = 1, b = 2, c = 3, d = 4;
//	//i = a++ || ++b || d++;
//	//printf("%d %d %d %d ", a, b, c, d);
//	//return 0;
//
//}

//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	int b = 0;
//	int max = 0;
//	if (a > 5)
//		b = 3;
//	else
//	    b = -3;
//	b = (a > 5 ? 3 : -3);
//	max = (a > b ? a:b);
//	printf("%d\n", max);
//	return 0;
//}

#include<stdio.h>
struct s
{
	char name[20];
	int age;
	char number[10];
};
int main()
{
	int a = 10;
	struct s s1 = { "小明",21, "19310532" };
	struct s* p = &s1;
	printf("%s\n", (*p).name);
	printf("%s\n", p->name);
	return 0;
}