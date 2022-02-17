#include <bits/stdc++.h>
using namespace std;

long long sum[100010];

int main()
{
    int n, m;
    while (cin >> n)
    {
        cin >> m;
        memset(sum, 0, sizeof(sum));
        cin>>sum[0];
        for (int i = 1; i < n; i++)
        {
            int rt;
            cin >> rt;
            sum[i] = sum[i - 1] + rt;
        }
        while (m--)
        {
            int a, b;
            int bg, ed;
            cin >> a >> b;
            bg = min(a, b);
            ed = max(a, b);
            if (bg == 1)
                cout << sum[ed - 1] << endl;
            else
                cout << sum[ed - 1] - sum[bg - 2] << endl;
        }
    }

    return 0;
}