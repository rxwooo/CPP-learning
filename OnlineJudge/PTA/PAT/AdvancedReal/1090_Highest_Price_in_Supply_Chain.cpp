#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    float rtPrice;
    float rate;
    unordered_map<int, vector<int>> node;
    int level = 0;

    cin >> n >> rtPrice >> rate;
    for(int i = 0; i < n; i ++)    
    {
        int tp;
        cin >> tp;
        node[tp].push_back(i);
    }
    vector<int> last = node[-1];
    while(1)
    {
        vector<int> cur;
        level++;
        for(int i = 0 ; i < last.size(); i ++)
            for(int j = 0; j < node[last[i]].size(); j++)
                cur.push_back(node[last[i]][j]);
        if(cur.size() == 0) 
            break;
        last = cur;
    }
    printf("%.2f %d", rtPrice * pow(rate/100 + 1, level - 1), last.size());
    return 0;
}