#include <bits/stdc++.h>
using namespace std;

long long LCD(long long a, long long b)
{
    long long xiao, da;
    xiao = min(a, b);
    da = max(a, b);
    if (xiao == 0)
        return da;
    long long tp = da % xiao;
    return LCD(xiao, tp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a *= c;
        b *= d;
        int tp = LCD(a,b);
        a /= tp;
        b /=tp;
        cout<<a<<" "<<b<<endl;
    }
}