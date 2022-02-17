#include <bits/stdc++.h>
using namespace std;

int num[15], vis[15], temp[6];
int len;

void dfs(int depth)
{
    if (depth > 1)
        if (temp[depth - 1] < temp[depth - 2])
            return;
    if (depth == 6)
    {
        for (int i = 0; i < 5; i++)
            printf("%d ", temp[i]);
        cout << temp[5] << endl;
        return;
    }

    for (int i = 1; i <= len; i++)
    {
        if (!vis[i])
        {
            temp[depth] = num[i];
            vis[i] = 1;
            dfs(depth + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    while (cin >> len, len)
    {
        for (int i = 1; i <= len; i++)
            cin >> num[i];
        memset(vis, 0, sizeof(vis));
        dfs(0);
        cout << endl;
    }
}