#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ep, fl, bg,n;
        int pr[10010], wei[10010],dp[10010];
        memset(dp, 0x3f3f, sizeof(dp));
        dp[0] = 0;

        cin >> ep >> fl;
        bg = fl - ep;
        cin >> n;

        for (int i = 1; i <= n; i++)
            cin >> pr[i] >> wei[i];

        for (int i = 1; i <= n; i++)
            for (int j = wei[i]; j <= bg; j++)
                dp[j] = min(dp[j], dp[j - wei[i]] + pr[i]);

        if (dp[bg] == 0x3f3f3f3f)
            cout << "This is impossible." << endl;
        else
            cout << "The minimum amount of money in the piggy-bank is " << dp[bg] << "." << endl;
    }
}

/*
3
10 110
2
1 1
30 50
10 110
2
1 1
50 30
1 6
2
10 3
20 4
*/