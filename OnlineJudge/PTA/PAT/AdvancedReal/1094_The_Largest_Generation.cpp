#include<bits/stdc++.h>
using namespace std;

int nodes[101];
int level[101];
int leCount[101];

int getLevel(int node)
{
    if(level[node] != 0)
        return level[node];
    if(node == nodes[node])
    {
        level[node] = 1;
        return 1;
    }
    level[node] = getLevel(nodes[node]) + 1;
    return level[node];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        level[i] = 0;
        nodes[i] = i;
        leCount[i] = 0;
    }
    while(m--)
    {
        int k, fath, child;
        cin >> fath >> k;
        while(k--)
        {
            cin >> child;
            nodes[child] = fath;
        }
    }
    int maxLev = -1;
    for(int i = 1; i <= n; i++)
    {
        int le = getLevel(i);
        leCount[le] ++;
        maxLev = max(le, maxLev);
    }
    int ansLevel = maxLev, ansAmount = -1;
    for(int i = maxLev; i > 0; i --)
    {
        if(ansAmount < leCount[i])
        {
            ansLevel = i;
            ansAmount = leCount[i];
        }
    }
    cout << ansAmount << " " << ansLevel << endl;
    
    return 0;
}