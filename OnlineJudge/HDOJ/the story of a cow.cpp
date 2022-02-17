#include<iostream>

using namespace std;

int main()
{
    long long a[56]={1,2,3,4};
    for(int i=4;i<56;i++)
    {
        a[i]=a[i-1]+a[i-3];
    }
    int n;
    while (cin>>n,n)
    {
        cout<<a[n-1]<<endl;
    }
    return 0;
}