#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,c;
    int count = 0;
    unordered_map<int ,vector<int>> clmap;
    unordered_set<int> clset;
    cin >> n >> m >> c;
    for(int i = 1; i <= c; i++)
        clmap.insert({i, {}});
    while(n --)
    {
        int num;
        cin >> num;
        for(int i = 0; i < num; i++)
        {
            int color;
            cin >> color;
            clmap[color].push_back(i);
        }
    }
    for(int i = 1; i <= c; i++)
    {
        vector<int> tp = clmap[i];
        int len = tp.size();
        for(int j = 1; j < len; j++)
        {
            if(tp[j] - tp[j - 1] < m)
            {
                clset.insert(i);
                break;
            }
        }
        if(clset.find(i) != clset.end())
            break;
        if(len != 1)
            if(n - tp[len - 1] + tp[0] < m)
                clset.insert(i);
    }
    cout << clset.size();
    return 0;
}