#include <iostream>
using namespace std;

int* fnl()
{
    int *p=new int (5);
    return p;
}

int main()
{
    int* a=fnl();
    cout<<"the value of a is "<<*a<<endl;
    delete a;
    return 0;
}