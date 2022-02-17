#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        int num[1010];
        int add[1010];
        int mx = 0;
        memset(num, 0, sizeof(num));
        memset(add, 0, sizeof(add));
        for (int i = 1; i <= n; i++)
            cin >> num[i];

        for (int i = n; i > 0; i--)
            for (int j = i - 1; j > 0; j--)
                if (num[j] < num[i])
                    add[j] = max(add[j], add[i] + num[i]);

        for (int i = 1; i <= n; i++)
            if (num[i] + add[i] > mx)
                mx = num[i] + add[i];

        cout << mx << endl;
    }
}