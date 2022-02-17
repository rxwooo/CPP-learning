#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
char a[1000],b[1000];
int dp[1000][1000]={0};

int main()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(dp,0,sizeof(dp));
    while (scanf("%s %s",a,b)!=EOF)
    {
        for(int i=1;i<=strlen(a);i++)
        {
            for(int j=1;j<=strlen(b);j++)
            {
                if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        cout<<dp[strlen(a)][strlen(b)]<<endl;
    }
    
}
