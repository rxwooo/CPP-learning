#include<bits/stdc++.h>
using namespace std;

int mymap[202][202];
int dis[202]; //least cost
int vis[202]; //vis
int hap[202]; //now hap
int num[202]; // amount of nodes in the path
int path[202]; // recommand last node
int rawhap[202]; // rwa happiness
int dif[202]; //amount of difference ways to current node
int nodes, roads;

void dijkstra(int root)
{
    dis[root] = 0;
    hap[root] = 0;
    num[root] = 1;
    path[root] = root;
    int clo = root;
    for(int i = 0;  i <= nodes; i++)
    {
        int min = 0x3f3f3f3f;
        for(int j = 0; j < nodes; j++)
            if(!vis[j] && min >= dis[j])
            {
                min = dis[j];
                clo = j;
            }
        vis[clo] = 1;
        for(int j = 0; j < nodes; j++)
        {
            if(!vis[j])
            {
                if(dis[j] > dis[clo] + mymap[clo][j])
                {
                    dis[j] = dis[clo] + mymap[clo][j];
                    path[j] = clo;
                    num[j] = num[clo] + 1;
                    hap[j] = hap[clo] + rawhap[j];
                    dif[j] = 1;
                }
                else if(dis[j] == dis[clo] + mymap[clo][j])
                {
                    dif[j] ++;
                    if(hap[j] < hap[clo] + rawhap[j])
                    {
                        hap[j] = hap[clo] + rawhap[j];
                        path[j] = clo;
                        num[j] = num[clo] + 1;
                    }
                    else if(hap[j] == hap[clo] + rawhap[j])
                    {
                        if(num[j] > num[clo] + 1)
                        {
                            path[j] = clo;
                            num[j] = num[clo] + 1;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    memset(mymap, 0x3f, sizeof(mymap));
    string bgName;
    string edName = "ROM";
    unordered_map<string, int> city;
    vector<string> citys;
    cin >> nodes >> roads >> bgName;
    city.insert({bgName, 0});
    citys.push_back(bgName);
    for(int i = 1; i < nodes; i++)
    {
        string tpName;
        cin >> tpName;
        city.insert({tpName, i});
        citys.push_back(tpName);
        cin >> rawhap[i];
    }
    for(int i = 0; i < roads; i++)
    {
        string aName, bName;
        int tp;
        cin >> aName >> bName >> tp;
        mymap[city[aName]][city[bName]] = tp;
        mymap[city[bName]][city[aName]] = tp;
    }
    int bg = city[bgName];
    int ed = city[edName];
    if(bg == ed)
    {
        cout << 1 << " " << 0 << " " << rawhap[ed] << " " << rawhap[ed] << endl;
        cout << "ROM" << endl;
    }
    dijkstra(bg);

    stack<int> output;
    int difs = 1;
    while(ed != bg)
    {
        output.push(ed);
        difs *= dif[ed];
        ed = path[ed];
    }
    cout << difs << " " << dis[city[edName]] << " " << hap[city[edName]] << " " << hap[city[edName]]/(num[city[edName]] - 1) << endl;
    cout << bgName;
    while(output.size())
    {
        cout << "->" << citys[output.top()];
        output.pop();
    }
    return 0;
}