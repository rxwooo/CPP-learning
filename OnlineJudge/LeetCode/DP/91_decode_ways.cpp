#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s)
{
    if(s[0] == '0') return 0;
    int len = s.size();
    int dp[110];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < len; i++)
    {  
        dp[i+1] = (s[i]=='0'?0:dp[i]);
        if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')))
            dp[i+1] += dp[i-1];
    }
    return dp[len];
}

int main()
{
    string test = "11106";
    cout << numDecodings(test) << endl;
    return 0;
}