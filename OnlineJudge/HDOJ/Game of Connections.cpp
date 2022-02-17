#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a[201]={1,1,2};
    for(int i=3;i<201;i++)
    {
        for(int j=0;j<i/2;j++)
        {
            a[i]+=a[j]*a[i-1-j]*2;
        }
        if(i%2==1) a[i]+=a[i/2]*a[i/2];
    }
    int n;
    while(cin>>n,n!=-1)
    {
        cout<<a[n]<<endl;
    }
    return 0;
}