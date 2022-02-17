#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a[60] = {0, 1, 2};
        int bg, ed, dist;
        cin >> bg >> ed;
        dist = ed - bg + 1;
        for (int i = 3; i <= dist; i++)
            a[i] = a[i - 1] + a[i - 2];
        cout << a[dist - 1] << endl;
    }
}