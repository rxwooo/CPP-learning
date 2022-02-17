#include<bits/stdc++.h>
using namespace std;

long long LCD (long long a,long long b)
{
    long long xiao, da;
    xiao = min(a, b);
    da = max(a, b);
    if(xiao == 0) return da;
    long long tp = da % xiao;
    return LCD(xiao, tp);
}

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        cout<<a*b/LCD(a,b)<<endl;
    }
}