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
    long long t;
    cin >> t;
    while (t--)
    {
        long long num1, num2, n, tp;
        cin >> n;
        cin >> num1;
        while (--n)
        {
            cin >> num2;
            tp = num1 * num2 / LCD(num1, num2);
            num1 = tp;
        }
        cout << num1 << endl;
    }
}