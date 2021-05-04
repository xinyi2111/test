#include <stdio.h>
//int main()
//{
//	/*int a, b;
//	
//	printf("Please input two numbers.");
//	scanf_s("%d%d", &a, &b);
//	if (a > b)
//	{
//		int c = a%b;
//		if (c == 0)
//		{
//			printf("最大公约数为%d", b);
//		}
//		else
//		{
//			a = b;
//			b = c;
//			c = a%b;
//			printf("最大公约数为%d", b);
//		}
//	}
//	else if (a == b)
//	{
//		printf("最大公约数为%d", a);
//	}
//	else if (a < b)
//	{
//		int d = b%a;
//		if (d == 0)
//		{
//			printf("最大公约数为%d",a);
//		}
//		else
//		{
//			b = a;
//			a = d;
//			d= b%a;
//			printf("最大公约数为%d", a);
//		}
//	}
//*/
//	int n = 0;
//	for ( n =1000; n <= 2000; n++)
//	{
//		if (n % 4 == 0)
//		{
//			if (n % 100 != 0)
//			{
//				printf("闰年之一是%d\n", n);
//			}
//		}
//	}
//
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int n = 0;
//	for (i = 100; i < 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j <= i / 2; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (j>i / 2)
//		{
//			n++;
//			printf("%d ", i);
//		}
//	}
//
//
//	printf(" %d\n",n);
//	return 0;
//
//}
int year(int i)
{
	if ((i % 100 != 0) && (i % 4 == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int m = 0;
	int n = 0;
	scanf_s("%d,&m");
	n = year(m);
	if (n == 1){
		printf("是闰年",m);
	}
	else{
		printf("不是闰年",m);

	}
	return 0;
}