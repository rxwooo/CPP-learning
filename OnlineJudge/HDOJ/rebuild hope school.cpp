#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a[60] = {0, 1, 3};
    for (int i = 3; i < 57; i++)
    {
        a[i] = a[i - 1] + a[i - 2] * 2;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}