#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    unordered_set<int> parent;
    unordered_map<int, vector<int>> node;
    for(int i = 0; i < n; i++)
    {
        int pa;
        int ch;
        string s;
        cin >> pa;
        cin >> s;
        cin >> ch;
        if(parent.find(pa) == parent.end())
            parent.insert(pa);
        if(node.find(pa) == node.end())
            node.insert({pa,{ch}});
        else
            node[pa].push_back(ch);
    }
    int count = 0;
    int len = node.size();
    for(int i = 1; i <= n; i++)
    {
        if(node.find(i) != node.end())
        {
            if(node[i].size() == 2)
                if(parent.find(node[i][0]) == parent.end() && parent.find(node[i][1]) == parent.end())
                    count ++;
        }
    }
    cout << count << endl;
    return 0;
}