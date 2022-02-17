#include<bits/stdc++.h>

using namespace std;

int vis[200][200],bg1,bg2;
int m,n;
int sp[200][200];

void bfs();

struct node
{
    int x,y,time;
};


int main()
{
    while(cin>>n>>m)
    {
        int count=0;
        memset(vis,0,sizeof(vis));
        memset(sp,0x3f,sizeof(sp));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            if(c=='#') vis[i][j]=9;
            else if(c=='.') vis[i][j]=0;
            else if(c=='a') { count++; bg1=i; bg2=j;} 
            else if(c=='x') vis[i][j]=8;
            else if(c=='r') vis[i][j]=6;
        }
        if(count) bfs();
        else cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;

    }
}

void bfs()
{
    int min=0x3f3f3f3f;
    node cu,nx;
    cu.x=bg2;
    cu.y=bg1;
    cu.time=0;
    queue<node>qu;
    vis[cu.y][cu.x]=1;
    sp[cu.y][cu.x]=0;
    qu.push(cu);
    while(!qu.empty())
    {
        cu=qu.front();
        qu.pop();
        
        if(vis[cu.y][cu.x]==6) if(min>cu.time) min=cu.time;

        nx.x=cu.x+1;
        nx.y=cu.y;
        if(nx.x>=0&&nx.x<m&&nx.y>=0&&nx.y<n) 
        if(vis[nx.y][nx.x]!=9)
        {
            nx.time=cu.time+1;
            if(vis[nx.y][nx.x]==8) nx.time+=1;
            if(sp[nx.y][nx.x]>nx.time&&cu.time<=sp[cu.y][cu.x])
            {
                if(vis[nx.y][nx.x]==0) vis[nx.y][nx.x]=1;
                sp[nx.y][nx.x]=nx.time;
                qu.push(nx);
            }
        }
        nx.x=cu.x-1;
        nx.y=cu.y;
        if(nx.x>=0&&nx.x<m&&nx.y>=0&&nx.y<n) 
        if(vis[nx.y][nx.x]!=9)
        {
            nx.time=cu.time+1;
            if(vis[nx.y][nx.x]==8) nx.time+=1;
            if(sp[nx.y][nx.x]>nx.time&&cu.time<=sp[cu.y][cu.x])
            {
                if(vis[nx.y][nx.x]==0) vis[nx.y][nx.x]=1;
                sp[nx.y][nx.x]=nx.time;
                qu.push(nx);
            }
        }
        nx.x=cu.x;
        nx.y=cu.y+1;
        if(nx.x>=0&&nx.x<m&&nx.y>=0&&nx.y<n) 
        if(vis[nx.y][nx.x]!=9)
        {
            nx.time=cu.time+1;
            if(vis[nx.y][nx.x]==8) nx.time+=1;
            if(sp[nx.y][nx.x]>nx.time&&cu.time<=sp[cu.y][cu.x])
            {
                if(vis[nx.y][nx.x]==0) vis[nx.y][nx.x]=1;
                sp[nx.y][nx.x]=nx.time;
                qu.push(nx);
            }
        }
        nx.x=cu.x;
        nx.y=cu.y-1;
        if(nx.x>=0&&nx.x<m&&nx.y>=0&&nx.y<n) 
        if(vis[nx.y][nx.x]!=9)
        {
            nx.time=cu.time+1;
            if(vis[nx.y][nx.x]==8) nx.time+=1;
            if(sp[nx.y][nx.x]>nx.time&&cu.time<=sp[cu.y][cu.x])
            {
                if(vis[nx.y][nx.x]==0) vis[nx.y][nx.x]=1;
                sp[nx.y][nx.x]=nx.time;
                qu.push(nx);
            }
        }
    }
    if(min!=0x3f3f3f3f) cout<<min<<endl;
    else cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
}