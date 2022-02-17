#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int dp[505][10005]={0x3f3f3f3f};

int main()
{
    int c;
    cin>>c;
    while (c)
    {c--;
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<10005;i++) dp[0][i]=0;
        int p[505]={0},w[505]={0};
        int e,f;
        cin>>e>>f;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>p[i]>>w[i];
        for(int i=1;i<n;i++)
            for(int j=1;j<=f-e;j++)
                for(int k=j;k*w[i]<=j;k--)
                    dp[i][j]=min(dp[i][j],dp[i-1][j-k*w[i]]+k*p[i]);
        cout<<dp[n][f-e]<<endl;
    }
    
}