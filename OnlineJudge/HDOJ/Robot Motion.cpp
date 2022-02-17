#include<bits/stdc++.h>

using namespace std;

int dir[4][2] = { 0,-1, -1,0, 0,1, 1,0 };
int ti,tj,in,out,loop,ep;
int mp[15][15],sp[15][15];

void dfs(int ni,int nj,int st)
{
    if(ep) return;
    if(ni>ti||ni<1||nj>tj||nj<1) { ep=2; out=st-1; }
    if(!sp[ni + dir[ mp[ni][nj] ] [1]] [nj + dir[ mp [ni][nj] ] [0]])
    {
        sp[ni + dir[ mp[ni][nj] ] [1]] [nj + dir[ mp [ni][nj] ] [0]]=st+1;
        dfs(ni+ dir[ mp[ni][nj] ] [1],nj+ dir[ mp[ni][nj] ] [0],st+1);
    }
    else if(ep!=2)
    {
        out=sp[ni + dir[ mp[ni][nj] ] [1]] [nj + dir[ mp [ni][nj] ] [0]]-1;
        loop=st-sp[ni + dir[ mp[ni][nj] ] [1]] [nj + dir[ mp [ni][nj] ] [0]]+1;
        ep=1;
    }

}

int main()
{
    while(cin>>ti>>tj&&ti&&tj)
    {
        cin>>in;
        char c; 
        out=0; loop=0;
        memset(mp,0,sizeof(mp));
        memset(sp,0,sizeof(sp));
        ep=0;
        for(int i=1;i<=ti;i++) for(int j=1;j<=tj;j++) 
        { 
            cin>>c;
            if( c=='N' ) mp[i][j]=0;
            else if( c=='E' ) mp[i][j]=3;
            else if( c=='W' ) mp[i][j]=1;
            else if( c=='S' ) mp[i][j]=2;
        }
        sp[1][in]=1;
        dfs(1,in,1);

        if(ep==1) cout<<out<<" step(s) before a loop of "<<loop<<" step(s)"<<endl;
        else if(ep==2) cout<<out<<" step(s) to exit"<<endl;
    }
}