#include<stdio.h>
//int main()
//{
//	int a = 0x11223344;//һ��16����λ��4��������λ
//	/*int d = 1;*/
//	int* pa = &a;
//	//char* pc = &a;
//	//char* pc = &a;
//	/*int* c = &d;*/
//	//*pa = 0;
//	//*pc = 0;
//	printf("%p\n", pa);
//	printf("%p\n", pa + 1);
//	//printf("%c\n", c);
//	return 0;
//}
//
//int main()
//{
//	int arr1[10] = { 0 };
//	int* p = arr1;//������������Ԫ�ص�ַ
//	//ָ�����p��������һ��Ԫ�ص�ַ
//	return 0;

//int main()
//{
//	int* p;
//	*p = 20;
//	return 0;
//}

int main()
{
	int a = 0x11223344;
	int* p = &a;
	*p = 0;
	return 0;
}