#include<iostream>
using namespace std;

class String
{
	//Ç³¿½±´
public:
	String(const char *str= "")
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
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
	~String()
	{}


private:
	char*m_data;
};




void main()
{

}