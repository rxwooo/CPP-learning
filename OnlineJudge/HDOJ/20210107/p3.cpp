#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        int ck = a[0]*a[0] + a[1]*a[1];
        if(a[0]+a[1]<=a[2])
        {
            cout<<"Impossible!"<<endl;
            continue;
        }
        if(ck==a[2]*a[2])
            cout<<"Right triangle"<<endl;
        else if(ck < a[2]*a[2])
            cout<<"Obtuse triangle"<<endl;
        else if(ck > a[2]*a[2])
            cout<<"Acute triangle"<<endl;
    }
    return 0;
}