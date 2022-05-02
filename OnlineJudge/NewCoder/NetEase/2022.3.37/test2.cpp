#include<bits/stdc++.h>
using namespace std;

int dp[2][200010];

int dfs(string s, int pos, int flag)
{
    if(pos == s.length())
        return 0;

    if(dp[flag][pos] != -1)
        return dp[flag][pos];

    if(flag == 0)
    {
        dp[flag][pos] =  dfs(s, pos + 1, 1);
        return dp[flag][pos];
    }
    if(abs(s[pos - 1] - s[pos]) == 1 || s[pos - 1] == s[pos])
    {
        int p2 = dfs(s, pos + 1, 1);
        int p3 = dfs(s, pos + 1, 0) + s[pos] + s[pos - 1] - 'a' - 'a' + 2;
        dp[flag][pos] = max(p2, p3);
        return dp[flag][pos];
    }
    else 
    {
        dp[flag][pos] = dfs(s, pos + 1, 1);
        return dp[flag][pos];
    }
}

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    for(int i = 0; i <= len; i++)
    {
        dp[0][i] = -1;
        dp[1][i] = -1;
    }
    cout << dfs(s, 1, 1) << endl;
    return 0;
}