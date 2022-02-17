#include<bits/stdc++.h>
using namespace std;

int vis[50][50][50];
int a,b,c,t;
struct node {
    int x,y,z,time;
};

bool bfs()
{
    node cu,nx;
    queue<node> qu;
    cu.x=cu.y=cu.z=0;
    cu.time=0;
    qu.push(cu);
    vis[0][0][0]=1;
    int move[6][3]={0,0,1,0,0,-1,0,1,0,0,-1,0,1,0,0,-1,0,0};
    while(!qu.empty())
    {
        cu=qu.front();
        qu.pop();

        if(cu.x==a-1&&cu.y==b-1&&cu.z==c-1) if(cu.time<=t) { t=cu.time; return 1; } else return 0;

        for(int k=0;k<6;k++)
        {
            nx.x=cu.x+move[k][0];
            nx.y=cu.y+move[k][1];
            nx.z=cu.z+move[k][2];
            if(nx.x>=0&&nx.x<=a-1&&nx.y>=0&&nx.y<=b-1&&nx.z>=0&&nx.z<=c-1&&vis[nx.x][nx.y][nx.z]==0)
            {
                nx.time=cu.time+1;
                vis[nx.x][nx.y][nx.z]=1;
                qu.push(nx);
            }
        }
    }
    return 0;
}

int main()
{
    int n;cin>>n;
    while(n--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&t);
        for(int i=0;i<a;i++) for(int j=0;j<b;j++) for(int k=0;k<c;k++) scanf("%d",&vis[i][j][k]);
        if(bfs()) printf("%d\n",t); else printf("-1\n");
    }
    return 0;
}

