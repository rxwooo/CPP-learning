#include<bits/stdc++.h>
using namespace std;

int mymap[502][502];
bool vis[502];
int dis[502];
int people[502];
int hands[502];
int nodes, roads;

void Dijkstra(int root)
{
    vis[root] = 1;
    dis[root] = 0;
    int clo = root;
    hands[root] = people[root];

    for(int i = 0; i < nodes; i++)
    {
        int min = 0x3f3f3f3f;
        for(int j = 0; j < nodes; j++) 
            if(!vis[j] && dis[j] < min)
            {
                min = dis[j];
                clo = j;
            }
        vis[clo] = 1;
        for(int j = 0; j < nodes; j++)
            if(!vis[j])
            {
                if(dis[j] > dis[clo] + mymap[clo][j])
                {
                    dis[j] = dis[clo] + mymap[clo][j];
                    hands[j] = hands[clo] + people[j];
                }
                else if(dis[j] == dis[clo] + mymap[clo][j])
                    hands[j] = max(hands[clo] + people[j], hands[j]);
            }
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    memset(hands, 0, sizeof(hands));
    memset(mymap, 0x3f, sizeof(mymap));

    int bg, ed;
    cin >> nodes >> roads >> bg >> ed;
    for(int i = 0; i < nodes; i++)
        cin >> people[i];
    for(int i = 0; i < roads; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mymap[a][b] = c;
        mymap[b][a] = c;
    }
    Dijkstra(bg);
    cout << dis[ed] << " " << hands[ed];
}

// something wrong I do not know happened
// int main()
// {
//     bool ck[502];
//     memset(ck, 0, sizeof(ck)); 
//     unordered_map<int, vector<vector<int>>> road;
//     vector<int> people;
//     int n, rds, bg, ed;
//     cin >> n >> rds >> bg >> ed;
//     for(int i = 0; i < n; i++)
//     {
//         int tp;
//         cin >> tp;
//         people.push_back(tp);
//     }
//     while(rds--)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         road[a].push_back({b, c});
//         road[b].push_back({a, c});
//     }
//     vector<int> cost(n, 0x3f3f3f3f);
//     vector<int> hand(n, 0);
//     queue<int> todo;
//     todo.push(bg);
//     cost[bg] = 0;
//     hand[bg] = people[bg];
//     ck[bg] = 1;
//     while(todo.size() != 0)
//     {
//         int cur = todo.front();
//         todo.pop();
//         int len = road[cur].size();
//         int tar;
//         for(int i = 0; i < len; i++)
//         {
//             tar = road[cur][i][0];
//             if (ck[tar] == 0)
//             {
//                 ck[tar] = 1;
//                 todo.push(tar);
//             }
//             if(cost[tar] > road[cur][i][1] + cost[cur])
//             {
//                 cost[tar] = road[cur][i][1] + cost[cur];
//                 hand[tar] = people[tar] + hand[cur];
//                 ck[tar] = 0;
//             }
//             else if(cost[tar] == road[cur][i][1] + cost[cur])
//             {
//                 hand[tar] = max(hand[tar], people[tar] + hand[cur]);
//                 ck[tar] = 0;
//             }
//         }
//     }
//     cout << cost[ed] << " " << hand[ed] << endl;

//     return 0;
// }