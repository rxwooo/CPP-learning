#include <iostream>
using namespace std;

class Rectangle
{
public:
    Rectangle(double a = 0, double b = 0, double c = 0, double d = 0) : top(a), left(b), button(c), right(d) {}
    double gtop() const { return top; }
    double gbutton() const { return button; }
    double gleft() const { return left; }
    double gright() const { return right; }
    double area() const { return (top - button) * (right - left); }
    void wtop(double a) { top = a; }
    void wbutton(double a) { button = a; }
    void wleft(double a) { left = a; }
    void wright(double a) { right = a; }

private:
    double top, button, left, right;
};
int main()
{
    Rectangle r1(100,20,50,80);
    cout<<"area : "<<r1.area()<<endl;
    return 0;
}