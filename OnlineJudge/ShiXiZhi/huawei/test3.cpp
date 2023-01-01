#include <bits/stdc++.h>
using namespace std;

int target;
vector<int> dist;
vector<int> ped;
//unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> _map;

// int dfs(int pos, int fuel, int time, int it, int flag)
// {
//     if(_map.find(pos) != _map.end())
//     {
//         if(_map[pos].find(fuel) != _map[pos].end())
//         {
//             if(_map[pos][fuel].find(it) != _map[pos][fuel].end())
//             {
//                 if(_map[pos][fuel][it].find(flag) != _map[pos][fuel][it].end())
//                     return _map[pos][fuel][it][flag];
//             }
//         }
//     }
//     if(pos + fuel >= target)
//     {
//         _map[pos][fuel][it][flag] = time + (target - pos) / 100;
//         return time + (target - pos) / 100;
//     }
//     if(it >= dist.size())
//         return 0x3f3f3f3f;
//     if(flag == 1)
//     {
//         time += ped[it] + 1;
//         fuel = 1000;
//     }
//     int dis = dist[it];
//     if(dis > fuel)
//         return 0x3f3f3f3f;
//     int res0 = dfs(pos + dis, fuel - dis, time + (dis / 100), it + 1, 0);
//     int res1 = dfs(pos + dis, fuel - dis, time + (dis / 100), it + 1, 1);
//     _map[pos][fuel][it][flag] = min(res1, res0);
//     return min(res1, res0);
// }

int main()
{
    cin >> target;
    int n;
    cin >> n;
    vector<int> dp(target + 1, -1);
    int last = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        dist.push_back(a);
        ped.push_back(b);
        last = a;
    }
    dp[0] = 0;
    for(int i = 1; i <= 1000; i ++)
    {
        dp[i] = dp[i - 1] + 1;
    }
    for(int i = 0; i < n; i++)
    {
        int dis = dist[i];
        for(int j = dis; j <= target; j++)
        {
            if(j - dis == 1000)
                break;
            if(dp[j - dis] == -1)
                dp[j] = -1;
            else if(dp[j] == -1)
                dp[j] = dp[j - dis] + (ped[i] + 1) * 100 + dis;
            else
                dp[j] = min(dp[j], dp[j - dis] + (ped[i] + 1) * 100 + dis);
        }
    }
    if(dp[target] == -1)
        cout << -1 << endl;
    else
        cout << dp[target] / 100 << endl;
    return 0;
}
// 1500
// 4
// 300 2
// 600 1
// 1000 0
// 1200 0

// 1500
// 2
// 100 0
// 300 2