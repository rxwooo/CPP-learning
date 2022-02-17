#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,y,sp;
};

int bgx,bgy,edx,edy;
int mx,my;
int vis[12][12];
char mp[12][12];

void bfs()
{
    node cu,nx;
    cu.x=bgx;
    cu.y=bgy;
    cu.sp=0;
    vis[cu.x][cu.y]=1;
    mp[cu.x][cu.y]='.';
    queue<node> qu;
    qu.push(cu);
    while(!qu.empty())
    {
        cu=qu.front();
        qu.pop();

        if(cu.x==edx&&cu.y==edy)
        {
            cout<<cu.sp<<endl;
            return ;
        }

        //shang
        if(cu.y-1>0)
        {
            if(mp[cu.x][cu.y-1]=='.')
            {
                nx.y=cu.y-1;
                nx.x=cu.x;
                nx.sp=cu.sp+1;
                if(!vis[nx.x][nx.y])
                {
                    vis[nx.x][nx.y]=1;
                    qu.push(nx);
                }
            }
            else if(cu.y-2>0)
            {
                if(mp[cu.x][cu.y-2]=='.')
                {
                    nx.y=cu.y-2;
                    nx.x=cu.x;
                    nx.sp=cu.sp+1;
                    if(!vis[nx.x][nx.y])
                    {
                        vis[nx.x][nx.y]=1;
                        qu.push(nx);
                    }
                }
            }
        }

        //zuo
        if(cu.x-1>0)
        {
            if(mp[cu.x-1][cu.y]=='.')
            {
                nx.y=cu.y;
                nx.x=cu.x-1;
                nx.sp=cu.sp+1;
                if(!vis[nx.x][nx.y])
                {
                    vis[nx.x][nx.y]=1;
                    qu.push(nx);
                }
            }
            else if(cu.x-2>0)
            {
                if(mp[cu.x-2][cu.y]=='.')
                {
                    nx.y=cu.y;
                    nx.x=cu.x-2;
                    nx.sp=cu.sp+1;
                    if(!vis[nx.x][nx.y])
                    {
                        vis[nx.x][nx.y]=1;
                        qu.push(nx);
                    }
                }
            }
        }

        //xia
        if(cu.y+1<=my)
        {
            if(mp[cu.x][cu.y+1]=='.')
            {
                nx.y=cu.y+1;
                nx.x=cu.x;
                nx.sp=cu.sp+1;
                if(!vis[nx.x][nx.y])
                {
                    vis[nx.x][nx.y]=1;
                    qu.push(nx);
                }
            }
            else if(cu.y+2<=my)
            {
                if(mp[cu.x][cu.y+2]=='.')
                {
                    nx.y=cu.y+2;
                    nx.x=cu.x;
                    nx.sp=cu.sp+1;
                    if(!vis[nx.x][nx.y])
                    {
                        vis[nx.x][nx.y]=1;
                        qu.push(nx);
                    }
                }
            }
        }

        //you
        if(cu.x+1<=mx)
        {
            if(mp[cu.x+1][cu.y]=='.')
            {
                nx.y=cu.y;
                nx.x=cu.x+1;
                nx.sp=cu.sp+1;
                if(!vis[nx.x][nx.y])
                {
                    vis[nx.x][nx.y]=1;
                    qu.push(nx);
                }
            }
            else if(cu.x+2<=mx)
            {
                if(mp[cu.x+2][cu.y]=='.')
                {
                    nx.y=cu.y;
                    nx.x=cu.x+2;
                    nx.sp=cu.sp+1;
                    if(!vis[nx.x][nx.y])
                    {
                        vis[nx.x][nx.y]=1;
                        qu.push(nx);
                    }
                }
            }
        }
    }
    cout<<"-1"<<endl;
    
}

int main()
{
    while(cin>>mx>>my)
    {
        for(int i=1;i<=my;i++)
        {
            for(int j=1;j<=mx;j++) cin>>mp[i][j];
        }
        memset(vis,0,sizeof(vis));
        cin>>bgx>>bgy>>edx>>edy;
        bfs();
    }
}