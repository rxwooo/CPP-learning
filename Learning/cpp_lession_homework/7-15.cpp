#include<iostream>

using namespace std;

struct Base1 {int x;};
struct Base2 {float y;};
struct Deriverd : Base1 ,Base2 {};

int main()
{
    Deriverd* pd=new Deriverd;
    pd->x=1;
    pd->y=0.2f;
    void *pv=pd;

    //原题代码为
    //Base2* pb=static_cast<Base2*> (pv); 
    //cout<<pd<<" "<<pb<<" "<<pv<<endl;
    Base2* pb=static_cast<Base2*> (pd);
    //cout<<pd<<" "<<pb<<" "<<pv<<endl;
    //代码更改前后可以看到pb的地址的数值与另外两个不同了
    //这说明数据成员相对于基类和派生类的偏移是不一样的
    cout<<pd->y<<" "<<pb->y<<endl;
    delete pb;
    return 0;
}



