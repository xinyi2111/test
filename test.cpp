#include<stdio.h>
//ö�ٹؼ�����enum

int main()
{
	char arr1[] = "abc";
	char arr2[] = {'a','b','c',0};//'\0'Ҳ���ַ������ַ��������ı�־������'\0'�����ֵ����0
	printf("%s\n", arr2);
	printf("%s\n", arr1);

	return 0;
}
//enum Sex
//{
//	MALE,//��Щ��ö�ٳ���
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

////#define ����ı�ʶ������
//#define MAX 10
//int main()
//{
//	const int sr = 5;
//	printf("%d",sr);
//	//sr = 6;//���ʻ��Ǳ�����ֻ�������г�����
//	//printf("%d", sr);
//	return 0;
//}