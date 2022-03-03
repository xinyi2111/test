#include<stdio.h>

enum Sex
{
	male,
	female
};
int main()
{
	int a = 10;
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(male));
	return 0;
}