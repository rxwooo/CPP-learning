#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double x = 0, double y = 0) : shi(x), xu(y) {}
    double gs() const { return shi; }
    double gx() const { return xu; }
    double &wx() { return xu; }
    double &ws() { return shi; }
    Complex& add(const Complex &a)
    {
        xu += a.gx();
        shi += a.gs();
        return *this;
    }
    void show() const { cout << shi << "+" << xu << "i" << endl; }
    Complex &operator=(const Complex &a)
    {
        shi = a.gs();
        xu = a.gx();
        return *this;
    }
    Complex &operator=(double &a)
    {
        shi = a;
        return *this;
    }

private:
    double xu;
    double shi;
};

int main()
{
    Complex c1(3, 5);
    Complex c2 = 4.5;
    c1.add(c2);
    c1.show();
    return 0;
}