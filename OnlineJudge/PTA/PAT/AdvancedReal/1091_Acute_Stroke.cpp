#include <bits/stdc++.h>
using namespace std;

bool mymap[1288][130][62];
bool vis[1288][130][62];
int m, n, l, t;

int mx[]={-1, 1, 0, 0, 0, 0};
int my[]={0, 0, -1, 1, 0, 0};
int mz[]={0, 0, 0, 0, -1, 1};

int bfs(int x, int y, int z)
{
    if(vis[x][y][z] || !mymap[x][y][z])
        return 0;
    vis[x][y][z] = 1;
    int re = 0;
    queue<vector<int>> todo;
    todo.push({x, y, z});
    while(todo.size())
    {
        x = todo.front()[0];
        y = todo.front()[1];
        z = todo.front()[2];
        todo.pop();
        re ++;
        for(int i = 0; i < 6; i++)
        {
            int nx = x + mx[i];
            int ny = y + my[i];
            int nz = z + mz[i];
            if(nx >= 0 && ny >= 0 && nz >= 0 && nx < m && ny < n && nz < l)
            if(!vis[nx][ny][nz] && mymap[nx][ny][nz])
            {
                todo.push({nx, ny, nz});
                vis[nx][ny][nz] = 1;
            }
        }
    }
    if(re >= t)
        return re;
    return 0;
}

int main()
{
    cin >> m >> n >> l >> t;
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int k = 0; k < l; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> mymap[i][j][k];
    for (int k = 0; k < l; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans += bfs(i, j ,k);
    cout << ans << endl;
    return 0;
}

    

// memory overflow 
// int m, n, l, t;
// bool mymap[1288][130][62];
// bool vis[1288][130][62];

// int dfs(int x, int y, int z)
// {
//     if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l || vis[x][y][z] || mymap[x][y][z] == 0)
//         return 0;

//     vis[x][y][z] = 1;
//     int count = 1;
//     count += dfs(x + 1, y, z);
//     count += dfs(x - 1, y, z);
//     count += dfs(x, y + 1, z);
//     count += dfs(x, y - 1, z);
//     count += dfs(x, y, z + 1);
//     count += dfs(x, y, z - 1);
//     return count;
// }

// int main()
// {
//     cin >> m >> n >> l >> t;
//     memset(vis, 0, sizeof(vis));
//     int ans = 0;
//     for (int k = 0; k < l; k++)
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 cin >> mymap[i][j][k];
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             for (int k = 0; k < l; k++)
//             {
//                 int tp = dfs(i, j, k);
//                 if (tp >= t)
//                     ans += tp;
//             }
//     cout << ans << endl;
//     return 0;
// }
