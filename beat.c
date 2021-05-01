//#include<stdio.h>
//#include<string.h>
//
//void* my_memcpy(void*dst,const void* src,size_t size)
//{
//	char*ch_dst = (char*)dst;
//	const char*ch_src = (const char*)src;
//	for (size_t i = 0; i < size; ++i)
//	{
//		ch_dst[i] = ch_src[i];
//	}
//	return dst;
//
//}
//void* my_memove(void*dst, const void* src, size_t size)
//{
//	char*ch_dst = (char*)dst;
//	const char*ch_src = (const char*)src;
//	if (ch_dst >= ch_src&&ch_dst <= ch_src + size)
//	{
//		for (int i = size - 1; i >= 0; --i)
//		{
//			ch_dst[i] = ch_src[i];
//		}
//	}
//	else{
//		for (size_t i = 0; i < size; ++i)
//		{
//			ch_dst[i] = ch_src[i];
//		}
//	}
//}
//int main()
//{
//	int a1[10] = { 1, 2, 3, 4.5 };
//	my_memcpy(a1 + 4, a1, 20);
//	my_memove(a1 + 4, a1, 20);
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>

void find_num(int arr[], int size, int* n1, int* n2)
{
	int i = 0;//ѭ������
	int xor_result = 0;//������������������Ľ��
	int dif_bit = 0;//�����������ֻ����һ�ε����ĵ�һ����ͬ�Ķ�����λ


	for (i = 0; i < size; i++)
	{
		xor_result ^= arr[i];
	}

	for (i = 0; i < 32; i++)
	{
		if (xor_result >> i)
		{
			dif_bit = i;
			break;
		}
	}

	for (i = 0; i < size; i++)
	{
		if ((arr[i] >> dif_bit) & 1)
			*n1 ^= arr[i];
		else
			*n2 ^= arr[i];
	}
}

int main()
{
	int num1 = 0;//������ŵ�һ��ֻ����һ�ε���
	int num2 = 0;//������ŵڶ���ֻ����һ�ε���
	int arr[] = { 1, 2, 3, 4, 1, 2, 3, 4, 5, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);//�������Ԫ�ظ���

	find_num(arr, size, &num1, &num2);//����ʵ�ֹ����Ӻ���

	printf("%d %d\n", num1, num2);
	system("pause");
	return 0;


