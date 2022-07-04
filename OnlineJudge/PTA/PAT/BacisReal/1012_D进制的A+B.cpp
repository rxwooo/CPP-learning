#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b;
    int d;
    string ans = "";
    cin >> a >> b >> d;
    int sum = a + b;
    while(sum > 0)
    {
        ans = (char)(sum % d + '0') + ans;
        sum /= d;
    }
    cout << ans << endl;
    return 0;
}