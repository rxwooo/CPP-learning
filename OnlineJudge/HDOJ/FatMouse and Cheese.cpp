#include <bits/stdc++.h>
using namespace std;

int mp[105][105];
int vis[105][105];
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
int edi, edj;
int n, k;
int m;

void dfs(int ni, int nj)
{
    if (ni < 1 || ni > n || nj < 1 || nj > n)
        return;
    if (vis[ni][nj] > m)
        m = vis[ni][nj];

    for (int d = 0; d < 4; d++)
    {
        for (int i = 1; i <= k; i++)
        {
            if (ni + dir[d][0] * i < 1 || ni + dir[d][0] * i > n || nj + dir[d][1] * i < 1 || nj + dir[d][1] * i > n)
                break;
            if (mp[ni + dir[d][0] * i][nj + dir[d][1] * i] > mp[ni][nj])
                if (vis[ni][nj] + mp[ni + dir[d][0] * i][nj + dir[d][1] * i] > vis[ni + dir[d][0] * i][nj + dir[d][1] * i])
                {
                    vis[ni + dir[d][0] * i][nj + dir[d][1] * i] = vis[ni][nj] + mp[ni + dir[d][0] * i][nj + dir[d][1] * i];
                    dfs(ni + dir[d][0] * i, nj + dir[d][1] * i);
                }
        }
    }
    return;
}

int main()
{
    while (cin >> n >> k)
    {
        if (n == -1 && k == -1)
            break;
        m = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> mp[i][j];
        memset(vis, 0, sizeof(vis));
        vis[1][1] = mp[1][1];
        dfs(1, 1);
        cout << m << endl;
    }
}