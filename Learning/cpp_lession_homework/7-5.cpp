#include<iostream>
using namespace std;

double PI=3.1415926;

class Shape{
public:
    Shape() {}
    ~Shape() {}
    virtual double GetArea() = 0;
};

class Circle : public Shape
{

public:
    Circle(double r):radius(r) {}
    ~Circle() {}

    double GetArea() { return PI*radius*radius; }

private:
    double radius;
};

class Rectangle : public Shape
{
public:
    Rectangle(double l,double w): len(l), wid(w) {}
    ~Rectangle() {}
    
    double GetArea() { return len*wid; }

private:
    double len,wid;

};

class square : public Rectangle
{
public:
    square (int l) : len(l),Rectangle(l,l) {}
    ~square() {}

private:
    double len;

};


int main()
{
    Shape *s;
    s=new Circle(5);
    cout<<"area of circle is "<<s->GetArea()<<endl;
    s=new Rectangle(3,4);
    cout<<"area of rectangle is "<<s->GetArea()<<endl;
    s=new square(4);
    cout<<"area of square is "<<s->GetArea()<<endl;
    return 0;
}