#include<bits/stdc++.h>

using namespace std;

class Object{
public:
    Object(double w=0):weight(w) { cout<<"bulid object"<<endl; }
    ~Object() {cout<<"~object"<<endl;}

private:
    double weight;
};

class Box:public Object
{
public:
    Box(int w=0,int h=0) : wid(w),hei(h) {cout<<"bulid Box"<<endl;}
    ~Box() { cout<<"~Box"<<endl;}
private:
    double hei, wid;
};

int main()
{
    Box b;
    return 0;
}