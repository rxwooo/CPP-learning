#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;
    while(m --)
    {
        int bg;
        int n;
        int low, up;
        int pri[12], wei[12], dp[1010];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        cin >> bg >> low >> up >> n;

        for(int i = 1; i <= n; i++)
            cin >> wei[i];

        for(int i = 1; i <= n; i++)
            for(int j = wei[i]; j <= bg; j++)
                dp[j] = min(dp[j], dp[j - wei[i]] + 1);

        int minN = 0x3f3f3f3f;
        for(int i = bg - up; i <= bg - low; i++)
            if(dp[i] < minN)
                minN = dp[i];

        if(minN == 0x3f3f3f3f)
            cout << 0 << endl;
        else
            cout << minN << endl;
    }
    return 0;
}