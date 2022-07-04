#include<bits/stdc++.h>
using namespace std;

int main()
{
    int start, num;
    cin >> start >> num;
    unordered_map<int, vector<int>> nodes;
    unordered_set<int> rmnode;
    vector<int> rm;
    for(int i = 0; i < num; i++)
    {
        int addr, val, next;
        cin >> addr >> val >> next;
        nodes[addr] = {val, next};
    }
    int bg = start;
    for(int i = 0; i < num; i++)
    {
        unordered_map<int, vector<int>>::iterator it = nodes.find(bg);
        if(rmnode.find(abs(it->second[0])) == rmnode.end())
        {
            rmnode.insert(abs(it->second[0]));
            it->second.push_back(1);
        }
        else
        {
            rm.push_back(it->first);
            it->second.push_back(0);
        }
        bg = it->second[1];
    }
    int len = rm.size();
    bg = start;
    printf("%05d %d ", bg, nodes[bg][0]);
    for(int i = 1; i < num - len;)
    {
        unordered_map<int, vector<int>>::iterator it = nodes.find(bg);
        if(nodes[it->second[1]][2] == 1)
        {
            printf("%05d\n%05d %d ", it->second[1], it->second[1], nodes[it->second[1]][0]);
            i++;
        }
        bg = nodes[bg][1];
    }
    cout << -1 << endl;
    for(int i = 0; i < len; i++)
    {
        printf("%05d %d ", rm[i], nodes[rm[i]][0]);
        if(i == len - 1)
            cout << -1 << endl;
        else
            printf("%05d\n", rm[i+1]);
    }
    return 0;
}