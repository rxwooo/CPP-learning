#include<iostream>

using namespace std;

class point{
private:
    int data;
    friend point operator ++ (point& p) { return point(p.getd()+1); }
    friend point operator ++ (point& p,int) { return point(p.getd()+1); }
    friend ostream& operator << (ostream& os,point a) { return os<<a.getd(); }

public:
    point (int n) :data(n) {}
    int getd () const { return data; }
};

int main()
{
    point p1(5);
    cout<<p1++<<endl;
    cout<<++p1<<endl;

    return 0;
}