#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> cvec;
vector<vector<int>> ans;

void generateMap()
{
    cvec.insert({'a', 0});
    cvec.insert({'b', 0});
    cvec.insert({'c', 0});
    cvec.insert({'x', 0});
    cvec.insert({'y', 0});
    cvec.insert({'z', 0});
}

bool checkEven()
{
    bool re = 1;
    re = re && (cvec['a'] % 2 == 0);
    re = re && (cvec['b'] % 2 == 0);
    re = re && (cvec['c'] % 2 == 0);
    re = re && (cvec['x'] % 2 == 0);
    re = re && (cvec['y'] % 2 == 0);
    re = re && (cvec['z'] % 2 == 0);
    return re;
}

int main()
{

    string str;
    cin >> str;
    generateMap();
    if (str.length() == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (cvec.find(str[0]) != cvec.end())
        cvec[str[0]]++;

    int len = str.length();
    int cur = 1;
    int bg = 0;

    while (cur < len)
    {
        char c = str[cur];
        if (cvec.find(c) != cvec.end())
        {
            cvec[c]++;
        }
        if (checkEven())
        {
            ans.push_back({bg, cur});
            while (cur >= bg)
            {
                if (cvec.find(str[bg]) != cvec.end())
                    cvec[str[bg]]--;
                bg++;
            }
        }
        cur++;
    }

    len = ans.size();
    if (len == 0)
        cout << 0 << endl;
    if (len == 1)
        cout << ans[0][1] - ans[0][0] + 1 << endl;
    if (len > 1)
    {
        int maxDis = ans[0][1] - ans[0][0];
        for (int i = 1; i < len; i++)
        {
            if (ans[i][0] == ans[i - 1][1] + 1)
                ans[i][0] = ans[i - 1][0];
            int dis = ans[i][1] - ans[i][0];
            if (dis > maxDis)
                maxDis = dis;
        }
        cout << maxDis + 1 << endl;
    }
    return 0;
}