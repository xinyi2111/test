#include<iostream>
#include<vector>
using namespace std;

//vector 大小可以动态改变底层空间是连续的空间
/*void main()
{
	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(ar) / sizeof(ar[0]);

	vector<int> iv(ar, ar + n);//通过数组初始化构造

	for (int i = 0; i<iv.size(); ++i)
		cout << iv[i] << " ";
	cout << endl;

	vector<int> iv1(iv.begin(), iv.end());//通过数组的起始迭代器和末尾迭代器来构造新数组
	//verctor(inputlterator begin,inputlterator end)
	vector<int> iv2(iv1);
	//拷贝构造函数初始化
	int iv3[] = { 1, 2, 3, 4, 5 };

	void main()
{
	vector<int> iv3{1,2,3,4,5,6,7,8,9,10};
	vector<int>::iterator it = iv3.begin();

	iv3.pop_back();
	auto pit = find(iv3.begin(), iv3.end(), 5);
	cout<<*pit<<endl;

	*pit = 20;
	iv3.erase(pit);


	while(it != iv3.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

void main()
{
	vector<int> iv3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int>::iterator it = iv3.begin();

	iv3.pop_back();
	auto pit = find(iv3.begin(), iv3.end(), 5);//find接口的实现
    //迭代器
	cout << *pit << endl;

	*pit = 20;//用指针将20把5替换
	iv3.erase(pit);
	auto pos2 = find(iv3.begin(), iv3.end(), 5);//在中间具体位置插入

	while (it != iv3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void main()
{
	//对迭代器失效进行举例
	vector<int> iv1{ 1, 2, 3, 4, 5 };
	auto it = find(iv1.begin(), iv1.end(), 3);
	//查找3的位置
	cout << *it << endl;
	iv1.push_back(10);
	//cout << *it << endl;
	//插入新的内容导致底层空间扩容，以前迭代的空间被释放，所以迭代器失效
	//重命名可以解决迭代器失效的问题
	//涉及到空间扩容或删除迭代器就可能会失效
	//保险起见可以重新赋值

	it = find(iv1.begin(), iv1.end(), 3);
	cout << *it << endl;

}

void main()
{
	//迭代器的删除
	vector<int> iv1{ 1, 2, 3, 4, 5 };
	auto it = find(iv1.begin(), iv1.end(), 3);

	cout << *it << endl;

	it = iv1.erase(it);

	cout << *it << endl;
}*/

int main()
{
	vector <int>iv4{ 1, 2, 3, 4};
	auto it = iv4.begin();
	while (it != iv4.end())
	{
		if (*it % 2 == 0)
		{
			it=iv4.erase(it);
			
			//需要重新赋值，不然2对应的迭代器失效
			//虽然编译通过但是结果不会出现
		}
		else
		{
			++it;
		}
	}
	for (auto &e : iv4)
		cout << e << " ";
	cout << endl;
	/*cout << "we"<< endl;*/


	return 0;

	

}