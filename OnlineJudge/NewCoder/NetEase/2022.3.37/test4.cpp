#include<bits/stdc++.h>
using namespace std;

int mymap[501][501];
int dp[501][501];
bool pos[501][501];
int n, m;

int dfs(int row, int col, int lastrow, int lastcol)
{
    if(row == n && col == m)
        return 0;
    if(row > n || col > m || row < 1 || col < 1)
        return 0x3f3f3f3f;

    int ck = mymap[row][col] == mymap[row][col - 1] ? 1: 2;
    int p1 = 0x3f3f3f3f;
    if(!(lastrow == row && lastcol + 1 == col))
        p1 = dfs(row, col - 1, row, col) + ck;

    ck = mymap[row][col] == mymap[row][col + 1] ? 1: 2;
    int p2 = 0x3f3f3f3f;
    if(!(lastrow == row && lastcol - 1 == col))
        p2 = dfs(row, col + 1, row, col) + ck;

    ck = mymap[row][col] == mymap[row + 1][col] ? 1: 2;
    int p3 = 0x3f3f3f3f;
    if(!(lastrow + 1 == row && lastcol == col))
        p3 = dfs(row + 1, col, row, col) + ck;

    dp[row][col] = min(p1, min(p2, p3));
    return dp[row][col];
}

int main()
{
    memset(dp, 0x3f, sizeof(dp));
    memset(mymap, 0, sizeof(mymap));
    memset(pos, 0, sizeof(pos));
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> mymap[i][j];
            dp[i][j] = -1;
        }
    int ans = dfs(1, 1, 0, 0);
    cout << ans << endl;
    return 0;
}