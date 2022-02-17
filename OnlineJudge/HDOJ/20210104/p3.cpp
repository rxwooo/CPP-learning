#include<bits/stdc++.h>
using namespace std;

int a[100010];
int n;

int main()
{
    while(cin>>n)
    {
        a[0] = a[1] = a[2] = 0;
        for(int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }
        for(int i = n; i > 0; i--)
        {
            if(i==n||i==n-1) continue;
            if(i==n-2) { a[i] += a[n]; continue;}
            a[i] += max(a[i+2],a[i+3]);   
        }
        cout<<max(a[1],a[2])<<endl;
    }
    return 0;
}
