#include <iostream>
using namespace std;

class SimpleCircle
{

public:
    SimpleCircle(int a) { itRadius = new int(a); }
    SimpleCircle(SimpleCircle &a) : itRadius(new int(a.getra())) {}
    ~SimpleCircle() { delete itRadius; }

    int getra() const { return *itRadius; }
    void writera(int a) { *itRadius = a; }
    double getarea () const {return (*itRadius)*(*itRadius)*3.1415926;}

private:
    int *itRadius;
};

int main()
{
    SimpleCircle s1(6);
    SimpleCircle s2(s1.getra());
    s1.writera(8);

    cout<<"the area of frist circle is "<<s1.getarea()<<endl;
    cout<<"the area of secend circle is "<<s2.getarea()<<endl;
    return 0;
}