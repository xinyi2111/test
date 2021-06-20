#include<iostream>
using namespace std;

class String
{
	//浅拷贝
public:
	String(const char *str= "")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
	String(const String &str)
	{
		m_data = new char[strlen(s.m_data)+1];
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		if (this != &s)
		{
			String tmp = s;
			std::swap(m_data, tmp.m_data);
		}
		return *this;
	}
	 
	String()
	{

	}
	~String()
	{}

	//浅拷贝会带来同一空间被多次释放的问题

private:
	char*m_data;
};




void main()
{

