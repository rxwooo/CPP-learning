#include <bits/stdc++.h>
using namespace std;

struct node{
    int bt,c1,c2,step;
};

int vis[110][110];
int but,cup1,cup2;

void bfs();

int main()
{
    while(cin>>but>>cup1>>cup2)
    {
        if(but==0&&cup1==0&&cup2==0) break;
        memset(vis,0,sizeof(vis));
        if(but%2==0&&but) bfs();
        else cout<<"NO"<<endl;
    }
}

void bfs()
{
    node cu,nx;
    cu.bt=but;
    cu.c1=0;
    cu.c2=0;
    cu.step=0;
    vis[cu.c1][cu.c2]=1;
    queue<node>qu;
    qu.push(cu);
    while(!qu.empty())
    {
        cu=qu.front();
        qu.pop();
        if((2*cu.bt==but&&cu.c2==0)||(2*cu.bt==but&&cu.c1==0))
        {
            cout<<cu.step<<endl;
            return ;
        }
        //c1 to c2
        if(cu.c1>(cup2-cu.c2))
        {
            nx.c1=cu.c1+cu.c2-cup2;
            nx.c2=cup2;
        }
        else
        {
            nx.c2=cu.c2+cu.c1;
            nx.c1=0;
        }
        nx.bt=cu.bt;
        if(!vis[nx.c1][nx.c2]&&cu.c1!=nx.c1)
        {
            nx.step=cu.step+1;
            vis[nx.c1][nx.c2]=1;
            qu.push(nx);
        }
        //c2 to c1
        if(cu.c2>(cup1-cu.c1))
        {
            nx.c2=cu.c1+cu.c2-cup1;
            nx.c1=cup1;
        }
        else
        {
            nx.c1=cu.c2+cu.c1;
            nx.c2=0;
        }
        nx.bt=cu.bt;
        if(!vis[nx.c1][nx.c2]&&cu.c2!=nx.c2)
        {
            nx.step=cu.step+1;
            vis[nx.c1][nx.c2]=1;
            qu.push(nx);
        }
        // bt to c1
        if(cu.c1!=cup1)
        {
            nx.c1=cup1;
            nx.c2=cu.c2;
            nx.bt=cu.bt+cu.c1-cup1;
            nx.step=cu.step+1;
            if(!vis[nx.c1][nx.c2])
            {
                vis[nx.c1][nx.c2]=1;
                qu.push(nx);
            }
        }
        // bt to c2
        if(cu.c2!=cup2)
        {
            nx.c2=cup2;
            nx.c1=cu.c1;
            nx.bt=cu.bt+cu.c2-cup2;
            nx.step=cu.step+1;
            if(!vis[nx.c1][nx.c2])
            {
                vis[nx.c1][nx.c2]=1;
                qu.push(nx);
            }
        }
        // c1 to bt
        if(cu.c1)
        {
            nx.c2=cu.c2;
            nx.bt=cu.c1+cu.bt;
            nx.c1=0;
            nx.step=cu.step+1;
            if(!vis[nx.c1][nx.c2])
            {
                vis[nx.c1][nx.c2]=1;
                qu.push(nx);
            }
        }
        // c2 to bt
        if(cu.c2)
        {
            nx.c1=cu.c1;
            nx.bt=cu.c2+cu.bt;
            nx.c2=0;
            nx.step=cu.step+1;
            if(!vis[nx.c1][nx.c2])
            {
                vis[nx.c1][nx.c2]=1;
                qu.push(nx);
            }
        }
    }
    cout<<"NO"<<endl;
    return ;
}
