#include<iostream>
#include<string>
#include<set> //集合
#include<map> //映射
#include<vector>
#include<functional>
using namespace std;

void main()
{
	pair<int, string> v[] = 
	{{3,"abc"}, {2,"xyz"},{1,"lmn"},{8,"opq"},{5,"asd"},
	{2,"xyz"},{1,"lmn"},{2,"xyz"},{1,"lmn"},{2,"xyz"},{1,"lmn"}};

	int n = sizeof(v) / sizeof(v[0]);

	multimap<int, string> mp;
	for(int i=0; i<n; ++i)
		mp.insert(v[i]);

	//mp[30] = "ABC";

	for(const auto &e : mp)
		cout<<e.first<<" : "<<e.second<<endl;
}

/*
void main()
{
	pair<int, string> v[] = {{3,"abc"}, {2,"xyz"},{1,"lmn"},{8,"opq"},{5,"asd"}};
	int n = sizeof(v) / sizeof(v[0]);

	map<int, string> mp;
	for(int i=0; i<n; ++i)
		mp.insert(v[i]);

	map<int,string>::iterator it = mp.begin();
	while(it != mp.end())
	{
		cout<<it->first<<" : "<<it->second<<endl;
		++it;
	}

	for(const auto &e : mp)
		cout<<e.first<<" : "<<e.second<<endl;
}

/*
void main()
{
	int ar[] = {10, 7, 8, 15, 5, 6, 15,15,15,15,15,15,11, 13, 12};
	int n = sizeof(ar) / sizeof(ar[0]);
	
	set<int> myset(ar, ar+n);

	cout<<"15 count = "<<myset.count(15)<<endl;

	for(const auto &e : myset)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	int ar[] = {10, 7, 8, 15, 5, 6, 11, 13, 12};
	int n = sizeof(ar) / sizeof(ar[0]);
	vector<int> iv = {10, 7, 8, 15, 5, 6, 11, 13, 12};
	//set<int> myset(iv.begin(), iv.end());
	set<int> myset(ar, ar+n);
	cout<<"size = "<<myset.size()<<endl;

	set<int>::iterator it = myset.begin();
	while(it != myset.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	auto it1 = myset.begin();
	while(it1 != myset.end())
	{
		cout<<*it1<<" ";
		++it1;
	}
	cout<<endl;

	for(const auto &e : myset)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	vector<int> iv = {10, 7, 8, 15, 5, 6, 11, 13, 12};
	set<int> myset;
	//set<int, greater<int>> myset;
	for(const auto &e : iv)
		myset.insert(e);

	set<int>::iterator it = myset.begin();
	while(it != myset.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	auto it1 = myset.begin();
	while(it1 != myset.end())
	{
		cout<<*it1<<" ";
		++it1;
	}
	cout<<endl;

	for(const auto &e : myset)
		cout<<e<<" ";
	cout<<endl;
}

/*
//值对结构 pair

void main()
{
	pair<int, string> p1 = make_pair<int,string>(1,"abc");
}

/*
/*
template<class _T1, class _T2> 
struct pair 
{
	typedef _T1 first_type;
	typedef _T2 second_type;

	pair(): first(_T1()), second(_T2()) 
	{}
	pair(const _T1& _V1, const _T2& _V2)
		: first(_V1), second(_V2) {}

	_T1 first;
	_T2 second;
};


void main()
{
	pair<int, string> p1{1, "abc"};
	cout<<p1.first<<" : "<<p1.second<<endl;
}*/