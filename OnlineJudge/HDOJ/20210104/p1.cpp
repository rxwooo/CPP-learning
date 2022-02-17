#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int l,t1,t2,v1,v2;
    double tb, tw;
    cin>>n;
    while(n--)
    {
        cin>>l>>t1>>t2>>v1>>v2;
        tb = t1 + t2 + l*1.0/v1;
        tw = l*1.0/v2;
        if(abs(tb-tw)<0.000001)
        {
            cout<<"Both are OK!"<<endl;
        }
        else if(tb<tw)
            cout<<"Bike is OK!"<<endl;
        else
        {
            cout<<"Walk is OK!"<<endl;
        }
    }
    return 0;
}