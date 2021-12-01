#include<stdio.h>
//int main()
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//
//}
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	printf("%d\n", *p);
////	return 0;
////}
//
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr1[] = "a,b,c,d,f";
//	int len = my_strlen(arr1);
//	printf("%d\n", len);
//	return 0;
//}

//利用指针-指针求字符串长度

//int my_strlen(char* str)
//{
//	char* start = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return str - start;
//
//}
//int main()
//{
//	char arr2[] = "asdfg";
//	int len = my_strlen(arr2);
//	printf("%d\n", len);
//	return 0;
//}

//int main()
//{
//
//	int arr[3][5] = {0}；
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	int** pp = &p;//二级指针
//	return 0;
//}

//指针数组，存放指针的数组
int main()
{
	int a = 10;
	int b = 2;
	int c = 3;
	int* arr[3] = {&a,&b,&c};//存放整型指针的数组
	char* p = "abcdef";
	printf("%s\n", p);
	char* arr1[] = { "abc", "hello", "world" };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%s\n",arr1[i]);

	}
	
	//字符指针数组
	return 0;
}