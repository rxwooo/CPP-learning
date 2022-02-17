#include<bits/stdc++.h>
using namespace std;

float ra[110];
int mon[110];
float dp[10010];

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        memset(dp,0,sizeof(dp));
        memset(ra,0,sizeof(ra));
        memset(mon,0,sizeof(mon));
        int n,tl=0;
        float tra;
        cin>>tra>>n;
        tra=1.0-tra;
        for(int i=1;i<=n;i++)
        {
            cin>>mon[i]>>ra[i];
            ra[i]=1.0-ra[i];
            tl+=mon[i];
        }
        dp[0]=1;

        for(int i=1;i<=n;i++)
        {
            for(int j=tl;j>=mon[i];j--)
            {
                dp[j] = max(dp[j],dp[j - mon[i]] * ra[i]);
            }
        }
        for(int i=tl;i>=0;i--)
        {
            if(dp[i]>=tra){
                cout<<i<<endl;
                break;
            }
        }
    }
        
    return 0;
}