#include<iostream>
#include<string>
#include<vld.h>
using namespace std;

//深拷贝 浅拷贝
class String
{
public:
	String(const char *str="")
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = new char[strlen(s.m_data)+1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			delete []m_data;  //异常不安全
			m_data = new char[strlen(s.m_data)+1];
			strcpy(m_data, s.m_data);
		}
		return *this;
	}
	~String()
	{
		delete []m_data;
		m_data = nullptr;
	}
private:
	char *m_data;
};

void main()
{
	//写时拷贝
	String s1("abc");//fjlajflajflaflafjalfjlfjlajflkjfjfajflkafljalfjalkfjal
	String s2("xyz");
	String s3 = s2;
	String s3 = s2;
	String s3 = s2;
	String s3 = s2;
	String s3 = s2;
	String s3 = s2;
	String s3 = s2;
}

/*
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void main()
{
	string str = "A man, a plan, a canal: Panama";
	cout<<str<<endl;
	//transform(str.begin(),str.end(), str.begin(), toupper);
	//transform(str.begin(),str.end(), str.begin(), tolower);

	reverse(str.begin(), str.end());

	cout<<str<<endl;
}

/*
size_t GetLengthOfLastWord(const string &str)
{
    size_t pos = str.rfind(' ');
    return str.size()-pos-1;  //-(-1)-1
}

int main()
{
    string str;
    getline(cin, str);
	size_t len = GetLengthOfLastWord(str);
    cout<<len;
    return 0;
}

/*
void main()
{
	string s1("abc");
	string s2("xyz");

	string ret = s1 + s2;
	cout<<ret<<endl;

	//string str;
	//cin>>str;
	//getline(cin, str);
	//cout<<str<<endl;

	if(s1 == s2)
		cout<<"s1>s2"<<endl;
	else
		cout<<"s1<=s2"<<endl;
}

/*
//python(接口)报表  java   C/C++可塑性强  Java  go php 解决问题
void main()
{
	string str("abcxyzhijkzllmn");
	string ret = str.substr(7, 3);
	cout<<ret<<endl;
}

/*
void main()
{
	string str("abcxyzhijkzllmn");

	//size_t index = str.find('x');
	size_t index = str.find('z', 6);

	if(index == string::npos)
		cout<<"不存在"<<endl;
	else
		cout<<"index = "<<index<<endl;
}

/*
void main()
{
	string str("1234");
	
	int value = atoi(str.c_str());

	cout<<"value = "<<value<<endl;
}

/*
void main()
{
	string str;
	str.push_back('a');
	str.push_back('b');
	str.push_back('c');
	str.append("xyz");
	str.append("sdfghjk", 4);
	cout<<str<<endl;  //abcxyzsdfg

	string str1("asd");
	//str1.append(str, 3, 3);
	//str1.append(str);
	//str1.append({'a','b','c'});
	//str1.append("abc");
	str1 += str;
	cout<<str1<<endl;
}

/*
void main()
{
	string str("abcxyz");
	cout<<str<<endl;  //1
	
	for(int i=0; i<str.size(); ++i)
		cout<<str[i]; //2
	cout<<endl;
	
	for(auto &e : str) //3
		cout<<e;
	cout<<endl;

	string::iterator it = str.begin();
	while(it != str.end())
	{
		cout<<*it;
		++it;
	}
	cout<<endl;

	auto it1 = str.begin();
	while(it1 != str.end())
	{
		cout<<*it1;
		++it1;
	}
	cout<<endl;

	string::reverse_iterator rit = str.rbegin();
	while(rit != str.rend())
	{
		cout<<*rit;
		++rit;
	}
	cout<<endl;

	auto rit1 = str.rbegin();
	while(rit1 != str.rend())
	{
		cout<<*rit1;
		++rit1;
	}
	cout<<endl;
}

/*
void main()
{
	string str;
	cout<<"str = "<<str<<endl;
	cout<<"size = "<<str.size()<<endl;  //STL
	cout<<"length = "<<str.length()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;
	cout<<"empty = "<<str.empty()<<endl;

	//str.reserve(100); //capacity
	str.resize(32, '@'); //size  length
	cout<<"========================="<<endl;

	cout<<"str = "<<str<<endl;
	cout<<"size = "<<str.size()<<endl;  //STL
	cout<<"length = "<<str.length()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;
	cout<<"empty = "<<str.empty()<<endl;

	//str.reserve(16); //capacity
	str.resize(10, '#');
	cout<<"========================="<<endl;

	cout<<"str = "<<str<<endl;
	cout<<"size = "<<str.size()<<endl;  //STL
	cout<<"length = "<<str.length()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;
	cout<<"empty = "<<str.empty()<<endl;
}


/*
void main()
{
	string str("abcxyz");
	//string str;
	cout<<"str = "<<str<<endl;
	cout<<"size = "<<str.size()<<endl;  //STL
	cout<<"length = "<<str.length()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;
	cout<<"empty = "<<str.empty()<<endl;

	str.clear();
	cout<<"========================="<<endl;

	cout<<"str = "<<str<<endl;
	cout<<"size = "<<str.size()<<endl;  //STL
	cout<<"length = "<<str.length()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;
	cout<<"empty = "<<str.empty()<<endl;
}

/*
void main()
{
	string s1;
	string s2("abc");
	string s3(10, 'a');
	string s4 = "xyz";
	string s5 = s4;
	string s6(s4, 1);
	string s7(s4.begin(), s4.end());
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"s3 = "<<s3<<endl;
	cout<<"s4 = "<<s4<<endl;
	cout<<"s5 = "<<s5<<endl;
	cout<<"s6 = "<<s6<<endl;
	cout<<"s7 = "<<s7<<endl;
}

/*
void main()
{
	char str[] = "jflafla";
	char *pstr = "abxyz";
	strlen(str);


	string s1 = "abc";
}
*/