#include <iostream>
using namespace std;

class Rectangle
{
public:
    Rectangle(double a = 0, double b = 0) : len(a), wi(b){}
    double glen() const { return len; }
    double gwi() const { return wi; }
    double area() const { return len*wi; }
    void wlen(double a) { len = a; }
    void wwi(double a) { wi = a; }

private:
    double len,wi;
};
int main()
{
    Rectangle r1(50,30);
    cout<<"area : "<<r1.area()<<endl;
    return 0;
}