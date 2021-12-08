#include<iostream>
using namespace std;

int a = 0;//全局变量

int main()
{
	short int age = 20;//短整型是两个字节16个比特位，能表示的最大值也就是2^16-1这个值
	int b = 1;//局部变量
	scanf("%d%d",&age,&b);//&是取地址符。把要输入的数字放在以前申请的地址里面
	return 0;
}