#include<stdio.h>
#include<iostream>

using namespace std;

class CPoint
{

public:

CPoint(double xd=0,double yd=0):x(xd),y(yd){

}

double GetX(){

return x;

}

double GetY(){

return y;

}

void SetX(double xi){

x=xi;

}

void SetY(double yi){

y=yi;

}

private:

double x,y;

};

class CRectangle

{

public:

CRectangle(const CPoint &a, const CPoint &b)

{

ldPoint=a;

ruPoint=b;

}

void SetLPoint(const CPoint& l)

{

ldPoint=l;

}

void SetRPoint(const CPoint& r)

{

ruPoint=r;

}

double GetPerimeter()

{

return (ruPoint.GetX()-ldPoint.GetX()+ruPoint.GetY()-ldPoint.GetY())*2;

}

double GetArea()

{

return (ruPoint.GetX()-ldPoint.GetX())*(ruPoint.GetY()-ldPoint.GetY());

}

private:

CPoint ldPoint,ruPoint;

};

int main(){

CPoint zuo(2,5),you(6,8);

CRectangle *rect=new CRectangle(zuo,you);

cout<<rect->GetPerimeter()<<endl<<rect->GetArea()<<endl;

zuo.SetX(4);

zuo.SetY(6);

you.SetX(7);

you.SetY(9);

rect->SetLPoint(zuo);

rect->SetRPoint(you);

cout<<rect->GetPerimeter()<<endl<<rect->GetArea()<<endl;

delete rect;

return 0;

}
