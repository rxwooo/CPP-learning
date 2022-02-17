#include <bits/stdc++.h>
using namespace std;

struct node
{
    int now;
    int sp;
};
int vis[210];
int num[210];
int bg,ed;
int n;

int bfs();

int main()
{
    while(cin>>n,n)
    {
        memset(vis,0,sizeof(vis));
        cin>>bg>>ed;
        int re;
        for(int i = 1;i<=n;i++) cin>>num[i];
        re = bfs();      
        cout<<re<<endl;  
    }
}

int bfs()
{
    node cu,nex;
    queue<node> qu;
    vis[bg] = 1;
    cu.now = bg;
    cu.sp = 0;
    qu.push(cu);
    while(!qu.empty())
    {
        cu = qu.front();
        qu.pop();
        if(cu.now == ed)
        {
            return cu.sp;
        }

        nex.now = cu.now-num[cu.now];
        if(nex.now>=1)
        {
            if(!vis[nex.now])
            {
                vis[nex.now] = 1;
                nex.sp = cu.sp+1;
                qu.push(nex);
            }
        }

        nex.now = cu.now+num[cu.now];
        if(nex.now<=n)
        {
            if(!vis[nex.now])
            {
                vis[nex.now] = 1;
                nex.sp = cu.sp+1;
                qu.push(nex);
            }
        }
    }
    return -1;
}