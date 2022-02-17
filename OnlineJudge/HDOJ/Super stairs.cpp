#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[50] = {9,0,1,2};
        int n;
        cin>>n;
        for(int i = 4;i<=n;i++)
            a[i] = a[i-1] + a[i-2];
        cout<<a[n]<<endl;
    }
}