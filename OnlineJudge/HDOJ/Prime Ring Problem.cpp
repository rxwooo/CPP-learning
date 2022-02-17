#include<bits/stdc++.h>
using namespace std;

int vis[20],ss[13]={2,3,5,7,11,13,17,19,23,29,31,37,41},ck[21];
int len,ep;

int prime(int x) {	 
	int i;
	for (i = 2; i <= x/2; i++)
		if (x % i == 0) return 0;
	return 1;
}

int check()
{
    int c=0;
    for(int j=2;j<=len;j++) if(prime(ck[j]+ck[j-1])) c++;
    if(prime(ck[1]+ck[len])) c++;
    if(c==len) return 1; else return 0;
}

void dfs(int depth)
{
    if( depth==len+1 ) 
        if(check()) { for(int i=1;i<len;i++) printf("%d ",ck[i]); cout<<ck[len]<<endl; return ; }
        else return;
    for(int i=2;i<=len;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ck[depth]=i;
            if(prime(ck[depth]+ck[depth-1]))
            { 
                dfs(depth+1);
            }
            vis[i]=0;
        }
    }
    return ;
}

int main()
{
    int count=0;
    while(cin>>len)
    {
        count++;
        ep=0;
        ck[1]=1;
        cout<<"Case "<<count<<":"<<endl;
        if(len==1||len%2==0) dfs(2);
        cout<<endl;
    }
}