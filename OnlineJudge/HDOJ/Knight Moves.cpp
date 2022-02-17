#include <bits/stdc++.h>
using namespace std;

int vis[9][9];
char c1,c2;;
int bg2,ed2,bg1,ed1;

struct node{
    int x,y,steps;
};

void bfs();

bool ck()
{
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<9;j++)
        {
            if(vis[i][j]==0) return 0;
        }
    }
    return 1;
}

void wt()
{
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<9;j++)
        {
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }
    return ;
}

int main()
{
    while(cin>>c1>>bg2>>c2>>ed2)
    {
        bg1=c1-'a'+1;ed1=c2-'a'+1;
        memset(vis,0,sizeof(vis));
        bfs();
        //wt();
    }
    return 0;
}


void bfs()
{
    node cu,nx;
    cu.steps=0;
    cu.x=bg1;cu.y=bg2;
    queue<node>qu;
    qu.push(cu);
    vis[cu.x][cu.y]=1;
    while(!qu.empty())
    {
        cu=qu.front();
        qu.pop();
        if(cu.x==ed1&&cu.y==ed2)
        {
            cout<<"To get from "<<c1<<bg2<<" to "<<c2<<ed2<<" takes "<<cu.steps<<" knight moves."<<endl;
            return ;
        }

        //if(ck()) return ;
        
        // if(cu.x==6&&cu.y==7)
        // {
        //     system("pause");
        // }
        // if(cu.x==7&&cu.y==6)
        // {
        //     system("pause");
        // }
        nx.x=cu.x+2;
        nx.y=cu.y+1;
        if(nx.x>0&&nx.x<9&&nx.y>0&&nx.y<9) if(!vis[nx.x][nx.y])
        {
            vis[nx.x][nx.y]=nx.steps=cu.steps+1;
            qu.push(nx);
        }

                
        nx.x=cu.x+2;
        nx.y=cu.y-1;
        if(nx.x>0&&nx.x<9&&nx.y>0&&nx.y<9) if(!vis[nx.x][nx.y])
        {
            vis[nx.x][nx.y]=nx.steps=cu.steps+1;
            qu.push(nx);
        }
        
        nx.x=cu.x-2;
        nx.y=cu.y+1;
        if(nx.x>0&&nx.x<9&&nx.y>0&&nx.y<9) if(!vis[nx.x][nx.y])
        {
            vis[nx.x][nx.y]=nx.steps=cu.steps+1;
            qu.push(nx);
        }
        
        nx.x=cu.x-2;
        nx.y=cu.y-1;
        if(nx.x>0&&nx.x<9&&nx.y>0&&nx.y<9) if(!vis[nx.x][nx.y])
        {
            vis[nx.x][nx.y]=nx.steps=cu.steps+1;
            qu.push(nx);
        }
        
        nx.x=cu.x+1;
        nx.y=cu.y+2;
        if(nx.x>0&&nx.x<9&&nx.y>0&&nx.y<9) if(!vis[nx.x][nx.y])
        {
            vis[nx.x][nx.y]=nx.steps=cu.steps+1;
            qu.push(nx);
        }
        
        nx.x=cu.x+1;
        nx.y=cu.y-2;
        if(nx.x>0&&nx.x<9&&nx.y>0&&nx.y<9) if(!vis[nx.x][nx.y])
        {
            vis[nx.x][nx.y]=nx.steps=cu.steps+1;
            qu.push(nx);
        }
        
        nx.x=cu.x-1;
        nx.y=cu.y+2;
        if(nx.x>0&&nx.x<9&&nx.y>0&&nx.y<9) if(!vis[nx.x][nx.y])
        {
            vis[nx.x][nx.y]=nx.steps=cu.steps+1;
            qu.push(nx);
        }
        
        nx.x=cu.x-1;
        nx.y=cu.y-2;
        if(nx.x>0&&nx.x<9&&nx.y>0&&nx.y<9) if(!vis[nx.x][nx.y])
        {
            vis[nx.x][nx.y]=nx.steps=cu.steps+1;
            qu.push(nx);
        }
    }
}