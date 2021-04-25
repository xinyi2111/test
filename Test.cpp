#include<iostream>
#include<vector>
using namespace std;

namespace bit58
{
	template<class _Ty>
	class vector
	{
	public:
		typedef _Ty*  iterator;
	public:
		vector():_start(nullptr),_finish(nullptr),_end(nullptr)
		{}
	public:
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end - _start;
		}
		bool empty()const
		{
			return size() == 0;
		}
	public:
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		void push_back(const _Ty &x)
		{
			insert(end(), x);
		}
	public:
		iterator insert(iterator _P, const _Ty &x)
		{
			int old_sz = size();
			int old_cap = capacity();

			if(old_sz+1 > old_cap)
			{
				//扩容

				size_t it_pos = _P - _start;

				size_t new_cap = old_cap==0 ? 1 : old_cap * 2;
				reserve(new_cap);

				//更新迭代器
				_P = _start + it_pos;
			}

			//移动数据
			iterator end = _finish++;
			while(end > _P)
			{
				*end = *(end-1);
				end--;
			}

			*_P = x;
			return _P;
		}
		void reserve(size_t n)
		{
			if(n > capacity())
			{
				int old_size = size();

				_Ty *new_base = new _Ty[n];

				if(_start)
				{
					memcpy(new_base, _start, sizeof(_Ty)*old_size);
					delete []_start;
				}

				_start = new_base;
				_finish = _start + old_size;
				_end = _start + n;
			}
		}
	private:

		iterator _start;
		iterator _finish;
		iterator _end;
	};
};

void main()
{
	bit58::vector<int> iv;

	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;

	//iv.reserve(10);
	//iv.insert(iv.begin(), 1);
	//iv.insert(iv.end(), 2);
	iv.push_back(1);
	iv.push_back(2);
	iv.push_back(3);

	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;

	auto it = iv.begin();
	while(it != iv.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}


/*
void  main()
{
	vector<vector<int>> vv;
	vv.resize(5);

	for(int i=0; i<5; ++i)
	{
		vv[i].resize(5);
	}

	for(int i=0; i<5; ++i)
	{
		for(int j=0; j<5; ++j)
		{
			cout<<vv[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*
int main()
{
	vector<int> v{ 1, 2, 4,3  };

	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}

	for(auto &e : v)
		cout<<e<<" ";
	cout<<endl;

	return 0;
}

/*
void main()
{
	vector<int> iv1{1,2,3,4,5};
	auto it = find(iv1.begin(), iv1.end(), 3);
	
	cout<<*it<<endl;

	it = iv1.erase(it);

	cout<<*it<<endl;
}

/*
void main()
{
	vector<int> iv1{1,2,3,4,5};
	auto it = find(iv1.begin(), iv1.end(), 3);

	cout<<*it<<endl;
	iv1.push_back(10);

	it = find(iv1.begin(), iv1.end(), 3);
	cout<<*it<<endl;

}

/*
void main()
{
	vector<int> iv1{1,2,3,4,5,6,7,8,9,10};

	for(int i=0; i<=iv1.size(); ++i)
		cout<<iv1[i]<<" ";
	cout<<endl;

	for(int i=0; i<=iv1.size(); ++i)
		cout<<iv1.at(i)<<" ";
	cout<<endl;

}

/*
void main()
{
	vector<int> iv1{1,2,3,4};
	vector<int> iv2{5,6};

	for(int i=0; i<iv1.size(); ++i)
		cout<<iv1[i]<<" ";
	cout<<endl;
	
	for(int i=0; i<iv2.size(); ++i)
		cout<<iv2[i]<<" ";
	cout<<endl;

	//iv1.swap(iv2);
	//iv1.assign(iv2.begin(), iv2.end());
	iv1.assign(10, 8);

	for(int i=0; i<iv1.size(); ++i)
		cout<<iv1[i]<<" ";
	cout<<endl;
	
	for(int i=0; i<iv2.size(); ++i)
		cout<<iv2[i]<<" ";
	cout<<endl;

}

/*
void main()
{
	vector<int> iv1{1,2,3,4};
	vector<int> iv2{5,6,7,8,9,10};

	
	for(int i=0; i<iv1.size(); ++i)
		cout<<iv1[i]<<" ";
	cout<<endl;
	
	for(int i=0; i<iv2.size(); ++i)
		cout<<iv2[i]<<" ";
	cout<<endl;

	iv1.swap(iv2);

	
	for(int i=0; i<iv1.size(); ++i)
		cout<<iv1[i]<<" ";
	cout<<endl;
	
	for(int i=0; i<iv2.size(); ++i)
		cout<<iv2[i]<<" ";
	cout<<endl;

}

/*
void main()
{
	vector<int> iv3{1,2,3,4,5,6,7,8,9,10};

	vector<int>::iterator pos =iv3.begin();

	iv3.insert(pos, 100);
	vector<int>::iterator pos1 = iv3.end();
	iv3.insert(pos1, 200);

	auto pos2 = find(iv3.begin(), iv3.end(), 5);
	//iv3.insert(pos2, 3, 300);
	iv3.insert(pos2, iv3.begin(), iv3.end());

	auto it = iv3.begin();
	while(it != iv3.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
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

/*using namespace std;

void main()
{
	vector<int> iv;
	//iv.resize(10);
	iv.reserve(100);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.reserve(10);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
}

/*
void  main()
{
	vector<int> iv;

	iv.reserve(100); //预留出来

	for(int i=0; i<100; ++i)
	{
		iv.push_back(i);
		cout<<"size = "<<iv.size()<<endl;
		cout<<"capacity = "<<iv.capacity()<<endl;
	}
}

/*
void  main()
{
	vector<int> iv;
	for(int i=0; i<100; ++i)
	{
		iv.push_back(i);
		cout<<"size = "<<iv.size()<<endl;
		cout<<"capacity = "<<iv.capacity()<<endl;
	}
}


/*
void main()
{
	vector<int> iv;
	iv.push_back(1);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;

	iv.resize(100);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;

	iv.resize(10);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
}

/*
void main()
{
	vector<int> iv;
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.push_back(1);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.push_back(2);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.push_back(3);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.push_back(4);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.push_back(5);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.push_back(6);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
	iv.push_back(7);
	cout<<"size = "<<iv.size()<<endl;
	cout<<"capacity = "<<iv.capacity()<<endl;
}

/*
void main()
{
	vector<int> iv3{1,2,3,4,5,6,7,8,9,10};
	vector<int>::iterator it = iv3.begin();
	while(it != iv3.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	vector<int>::reverse_iterator rit = iv3.rbegin();
	while(rit != iv3.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;
}


/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(ar) / sizeof(ar[0]);

	vector<int> iv(ar, ar+n);

	for(int i=0; i<iv.size(); ++i)
		cout<<iv[i]<<" ";
	cout<<endl;

	vector<int> iv1(iv.begin(), iv.end());
	for(const auto &e : iv1)
		cout<<e<<" ";
	cout<<endl;

	vector<int> iv2(iv1); //iv2 = iv1;
	for(const auto &e : iv2)
		cout<<e<<" ";
	cout<<endl;

	//对向量进行初始化  C++11支持
	vector<int> iv3{1,2,3,4,5,6,7,8,9,10};
	for(const auto &e : iv3)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	vector<int> iv1;
	vector<int> iv2(10, 5);

	for(int i=0; i<iv2.size(); ++i)
		cout<<iv2[i]<<" ";
	cout<<endl;

	for(const auto &e : iv2)
		cout<<e<<" ";
	cout<<endl;

	//vector<int>::iterator it = iv2.begin();
	auto it = iv2.begin();
	while(it != iv2.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
vector  动态数组

class SeqList
{};

void main()
{
	int ar[100] = {0};
}
*/