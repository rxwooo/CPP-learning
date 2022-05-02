#include<bits/stdc++.h>
using namespace std;

int x, y;
int dp[22][22];

int dfs(int a, int b)
{
    if(a <= 0 && b <= 0)
        return 0;

    if(dp[a][b] != -1)
        return dp[a][b];

    int ans = 0;
    if(a <= 0 && b > 0)
    {
        ans =  dfs(a, b - max(x, y)) + 1;
        dp[a][b] = ans;
        return ans;
    }
    if(a > 0 && b <= 0)
    {
        ans = dfs(a - max(x, y), b) + 1;
        dp[a][b] = ans;
        return ans;
    }
    if(y > x)
    {
        ans = dfs(a - y, b - y) + 1;
        dp[a][b] = ans;
        return ans;
    }
    int p1, p2, p3;
    p1 = dfs(a - x, b) + 1;
    p2 = dfs(a, b - x) + 1;
    p3 = dfs(a - y, b - y) + 1;
    ans =  min(p1, min(p2, p3));
    dp[a][b] = ans;
    return ans;
}

int main()
{
    for(int i = 0; i < 22; i++)
        for(int j = 0; j < 22; j++)
            dp[i][j] = -1;
    int a, b;
    cin >> a >> b >> x >> y;
    int ans = dfs(a, b);
    cout << ans << endl;
    return 0;
}