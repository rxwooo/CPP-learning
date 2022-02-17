#include <iostream>
using namespace std;

class Circle
{
public:
    Circle(double a = 0) : radius(a) {}
    Circle(const Circle &a) : radius(a.getr()) {}
    double getr() const { return radius; }
    void wirter(double a) { radius = a; }
    double getArea() const { return radius * radius * 3.1415926; }

private:
    double radius;
};

int main()
{
    Circle c1(5), c2(c1);
    cout << c2.getArea() << endl;
    return 0;
}