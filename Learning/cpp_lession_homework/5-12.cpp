#include <iostream>
using namespace std;

void fnl()
{
    static int n=0;
    n++;
    cout<<"the value of n is "<<n<<endl;
}

int main()
{
    for(int i=0;i<10;i++) fnl();
    return 0;
}