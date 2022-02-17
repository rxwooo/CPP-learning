#include <bits/stdc++.h>
using namespace std;

int main()
{
    int bg, n;
    while (cin>>bg>>n)
    {
        if(bg==-1)  break;
        int pr[10010], wei[10010],dp[10010];
        memset(dp, 0xc0, sizeof(dp));
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
            cin >> pr[i] >> wei[i];

        for (int i = 1; i <= n; i++)
            for (int j = bg; j >= wei[i]; j--)
                dp[j] = max(dp[j], dp[j - wei[i]] + pr[i]);

        if (dp[bg] < 0)
            cout << "-1" << endl;
        else
            cout << dp[bg] << endl;
    }
}