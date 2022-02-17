#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    int n;
    int flag;
    cin>>n;
    flag = n;
    while(n--)
    {
        cin>>a>>b>>c;
        cout << "Case #" << flag - n << ": ";
        if(!(a+b>c&&a+c>b&&b+c>a))
        {
            cout<<"invalid!" << endl;
            continue;
        }
        if(a==b&&a==c)
        {
            cout<<"equilateral" << endl;
            continue;
        }
        if(a==b||a==c||b==c)
            cout<<"isosceles" << endl;
        else 
            cout<<"scalene" << endl;
    }
    return 0;
}

