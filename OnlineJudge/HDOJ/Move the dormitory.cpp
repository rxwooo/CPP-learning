#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[2001][2001];
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        memset(dp,0x3f3f3f3f,sizeof(dp));
        int a[2001]={0},count=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n-1;i++)
        {
            a[i]=a[i+1]-a[i];
            a[i]*=a[i];
        }
        dp[0][0]=dp[1][0]=0;
        for(int i=2;i<=n;i++)
        {
            dp[i][0]=0;
            for(int j=1;j<=k;j++)
            {
                dp[i][j]=min(dp[i-2][j-1]+a[i-2],dp[i-1][j]);
            }
        }
        cout<<dp[n][k]<<endl;
    }
}