#include<bits/stdc++.h>
using namespace std;

int dp[50*100*50+10];
int va[50*100*50+10];

int main()
{
    int n;
    while(cin>>n,n>=0)
    {
        memset(dp,0,sizeof(dp));
        memset(va,0,sizeof(va));
        int num=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            int count,value;
            cin>>value>>count;
            for(int j=0;j<count;j++)
            {
                va[++num]=value;
                sum+=value;
            }
        }
        int ha=sum/2;
        for(int i=1;i<=num;i++)
        {
            for(int j=ha;j>=va[i];j--)
            {
                dp[j]=max(dp[j],dp[j - va[i] ] + va[i]);
            }
        }
        cout<<sum-dp[ha]<<" "<<dp[ha]<<endl;
    }
}