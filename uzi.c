//#include<stdio.h>
//
//int main()
//{
//	int i = 0;
//	int m = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (9 == i % 10 || 9 == i / 10)
//			m++;
//	}
//	printf("����Ϊ%d\n", m);
//	return 0;
//}
//
#include<stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int k = 1;
	int num = sizeof(arr) / sizeof(arr[0]);

	int left = 0;
	int right = num - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}


		else
		{
			printf("�ҵ��ˣ�%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("�Ҳ�����\n");
	}

	return 0;
}
