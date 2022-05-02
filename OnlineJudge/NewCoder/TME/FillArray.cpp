#include <bits/stdc++.h>
using namespace std;

int limit;
unordered_map<int, unordered_map<int, int>> dpMap;

int dfs(int pos, int base, vector<int> &vec)
{
    if (pos == vec.size())
        return 1;
    int ans = 0;
    vector<int> tp = {pos, base};
    if (dpMap.find(pos) != dpMap.end())
        if(dpMap[pos].find(base) != dpMap[pos].end())
            return dpMap[pos][base];
        else
            dpMap[pos].insert({base, 0});
    else {
        unordered_map<int ,int> tp;
        tp.insert({base, 0});
        dpMap.insert({pos, tp});
    }
        
    if (vec[pos] != 0)
        if (vec[pos] < base)
            ans = 0;
        else
            ans = dfs(pos + 1, max(base, vec[pos]), vec);
    else
    {
        int now = base;
        while (now <= limit)
        {
            int re = dfs(pos + 1, now, vec);
            ans += re;
            now++;
        }
    }
    dpMap[pos][base] = ans;
    return ans;
}

int FillArray(vector<int> &a, int k)
{
    limit = k;
    return dfs(0, 1, a);
}

int main()
{   
    vector<int> tp = {1, 0, 0};
    cout << FillArray(tp, 3) << endl;
    return 0;
}