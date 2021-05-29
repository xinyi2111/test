#include<iostream>

#include<string>

using namespace std;

class Fan
{
public:
	int speed,radius;
	string on;
	string color;
	void display()
	{
		cout << speed << " ";
		cout << radius << " ";
		cout << color << " ";
		cout << on<< endl;
	}
}; 
int main()
{
	Fan f1, f2;
	cout << "speed£¬radius£¬color£¬on or off"<< endl;
	cin >> f1.speed >>f1.radius >> f1.color >> f1.on;
	cout <<"speed£¬radius£¬color£¬on or off" << endl;
	cin >> f2.speed >>f2.radius >> f2.color >> f1.on;
	cout << "The first fan"<< endl; 
	f1.display();
	cout << "The second fan"<< endl; 
	f2.display();
	return 0;
	
	
}
