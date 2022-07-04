#include<bits/stdc++.h>
using namespace std;

int dp[100010];

int main()
{
    int t;
    cin >> t;
    memset(dp, 0, sizeof(dp));
    while(t --)
    {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++)
        {
            int tp;
            cin >> tp;
            dp[i] = tp;
        }
        sort(dp, dp + n);
        int sum = 1;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            sum *= dp[i];
            if(sum <= k) count ++;
            else break;
        }
        cout << count << endl;
    }
    return 0;
}