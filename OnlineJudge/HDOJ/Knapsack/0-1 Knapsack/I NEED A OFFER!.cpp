#include<bits/stdc++.h>
using namespace std;

int fee[10010];
double ra[10010];
double dp[10010];

int main()
{
    long long tfe, num;
    while (cin>>tfe>>num, tfe||num)
    {
        int tl=0;
        for (int i=1;i<=num;i++)
        {
            cin>>fee[i]>>ra[i];
            ra[i]=1-ra[i];
            tl+=fee[i];
        }
        for (int i=0;i<=tfe;i++) dp[i]=1;

        for (int i=1;i<=num;i++)
        {
            for (int j=tfe;j>=fee[i];j--)
            {
                dp[j]=min(dp[j], dp[j - fee[i]] * ra[i]);
            }
        }

        printf("%.1f%%\n", 100 * (1 - dp[tfe]));
    }
}