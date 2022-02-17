#include <bits/stdc++.h>
using namespace std;

long long num[100010][13];

int main()
{
    int n;
    while (cin >> n, n)
    {
        int maxt = 0;
        memset(num, 0, sizeof(num));

        for (int i = 0; i < n; i++)
        {
            int t, p;
            cin >> p >> t;
            if (maxt < t)
                maxt = t;
            num[t][p + 1]++;
        }

        for (int i = maxt - 1; i >= 0; i--)
            for (int j = 1; j <= 11; j++)
                num[i][j] += max(max(num[i + 1][j - 1], num[i + 1][j]), num[i + 1][j + 1]);

        cout << num[0][6] << endl;
    }
}