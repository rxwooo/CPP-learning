#include <bits/stdc++.h>
using namespace std;
int n, m, ti, edj, edi, bgi, bgj;
bool ep;
int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int mp[9][9] = {0};

void dfs(int si, int sj, int cnt)
{
    int i, temp;
    if (si > n || sj > m || si <= 0 || sj <= 0)
        return;
    if (cnt == ti && si == edi && sj == edj)
        ep = 1;
    if (ep)
        return;
    temp = (ti - cnt) - abs(si - edi) - abs(sj - edj);
    if (temp < 0 || temp % 2 == 1)
        return;
    for (i = 0; i < 4; i++)
    {
        if (mp[si + dir[i][0]][sj + dir[i][1]] != 1)
        {
            mp[si + dir[i][0]][sj + dir[i][1]] = 1;
            dfs(si + dir[i][0], sj + dir[i][1], cnt + 1);
            mp[si + dir[i][0]][sj + dir[i][1]] = 0;
        }
    }
    return;
}

int main()
{
    while (cin >> n >> m >> ti)
    {
        if (n == 0 && n == 0 && ti == 0)
            break;
        ep = 0;
        int wall = 0;
        memset(mp, 0, sizeof(mp));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                if (c == 'X')
                {
                    mp[i][j] = 1;
                    wall++;
                }
                else if (c == 'D')
                {
                    edi = i;
                    edj = j;
                }
                else if (c == 'S')
                {
                    bgi = i;
                    bgj = j;
                }
            }
        if (m * n - wall <= ti)
        {
            cout << "NO" << endl;
            continue;
        }
        mp[bgi][bgj] = 1;
        dfs(bgi, bgj, 0);
        if (ep)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}