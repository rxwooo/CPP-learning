#include<iostream>
using namespace std;

double PI=3.1415926;

class Shape{
public:
    Shape() {}
    ~Shape() {}
    virtual double GetArea() = 0;
    virtual double GetPerim() = 0;
};

class Circle : public Shape
{

public:
    Circle(double r):radius(r) {}
    ~Circle() {}

    double GetArea() { return PI*radius*radius; }
    double GetPerim() {  return 2*PI*radius; }

private:
    double radius;
};

class Rectangle : public Shape
{
public:
    Rectangle(double l,double w): len(l), wid(w) {}
    ~Rectangle() {}
    
    double GetArea() { return len*wid; }
    double GetPerim() { return 2*(len+wid); }
private:
    double len,wid;

};

int main()
{
    Rectangle r1(3,4);
    Circle c1(5);
    cout<<r1.GetPerim()<<endl;
    cout<<r1.GetArea()<<endl;
    cout<<c1.GetPerim()<<endl;
    cout<<c1.GetArea()<<endl;

    return 0;
}