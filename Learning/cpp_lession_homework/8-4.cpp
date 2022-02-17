#include<iostream>

using namespace std;

class counter{
private:
    int data;
    friend ostream& operator << (ostream& os,counter a) { return os<<a.getd(); }

public:
    counter(int n):data(n) {}
    counter operator + (counter& a) { return counter(a.getd()+this->getd()); }
    counter operator + (int a) { return counter(a+this->getd()); }
    int getd () const { return data; }

};

int main()
{
    counter c1(5);
    counter c2(6);
    cout<<c1+4<<endl;
    cout<<c1+c2<<endl;
    return 0;
}