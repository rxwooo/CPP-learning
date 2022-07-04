#include<bits/stdc++.h>
using namespace std;

int mymap[502][502];
int vis[502];
int dis[502];
int bike[502];
int take[502][2];
int path[502];
int roads, nodes;
int cmax, ed;

vector<int> adj(int src, int dst)
{
    int give = bike[dst] - cmax/2;
    int src0 = take[src][0];
    int src1 = take[src][1];
    if(give < 0)
    {
        if(src0 < -give)
        {
            give += src0;
            src0 = 0;
            src1 += -give;
        }
        else
            src0 += give;
    }
    else if(give > 0)
        src0 += give;
    return {src0, src1};
}

void dijkstra(int root = 0)
{
    vis[root] = 1;
    bike[root] = 0;
    take[0][1] = 0;
    take[0][0] = 0;
    dis[0] = 0;
    int clo = root;
    for(int i = 0; i <= nodes; i++)
    {
        int min = 0x3f3f3f3f;
        for(int j = 0; j <= nodes; j++)
        {
            if(!vis[j] && dis[j] < min)
            {
                clo = j;
                min = dis[j];
            }
        }
        vis[clo] = 1;
        for(int j = 0; j <= nodes; j++)
        if(!vis[j])
        {
            if(dis[j] > dis[clo] + mymap[clo][j])
            {
                dis[j] = dis[clo] + mymap[clo][j];
                path[j] = clo;
                vector<int> tp = adj(clo, j);
                take[j][0] = tp[0];
                take[j][1] = tp[1];
            }
            else if(dis[j] == dis[clo] + mymap[clo][j])
            {
                vector<int> tp = adj(clo, j); 
                if(tp[1] < take[j][1])
                {
                    take[j][0] = tp[0];
                    take[j][1] = tp[1];
                    path[j] = clo;
                }
                else if(tp[1] == take[j][1])
                {
                    if(tp[0] > take[j][0])
                    {
                        take[j][0] = tp[0];
                        take[j][1] = tp[1];
                        path[j] = clo;
                    }
                }
            }
        }
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));    
    memset(dis, 0x3f, sizeof(vis));
    memset(mymap, 0x3f, sizeof(mymap));
    memset(take, 0, sizeof(take));

    cin >> cmax >> nodes >> ed >> roads;
    for(int i = 1; i <= nodes; i++)
        cin >>bike[i];
    for(int i = 1; i <= roads; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mymap[a][b] = c;
        mymap[b][a] = c;
    }
    dijkstra(0);
    stack<int> node;
    int pos = ed;
    while(pos != 0)
    {
        node.push(pos);
        pos = path[pos];
    }
    cout << take[ed][1] << " 0";
    while(node.size())
    {
        cout << "->" << node.top();
        node.pop();
    }
    cout << " " << take[ed][0];
    return 0;
}