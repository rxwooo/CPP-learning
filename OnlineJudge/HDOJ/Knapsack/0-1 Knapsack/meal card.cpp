#include <bits/stdc++.h>
using namespace std;

int cost[1010];
int dp[1010];

int main()
{
    int n;
    while (cin >> n, n)
    {
        memset(cost, 0, sizeof(cost));
        memset(dp,0,sizeof(dp));
        int mon, left;

        for (int i = 0; i < n; i++)
            cin >> cost[i];
        cin >> mon;
        if(mon<5) { cout<<mon<<endl; continue; }
        
        left = mon - 5;
        sort(cost, cost + n);

        if(left>=cost[0])
        {
            for(int meal=0;meal < n - 1;meal++)
            {
                for(int fee=left; fee>=cost[meal] ; fee--)
                {
                    dp[fee]=max(dp[fee],dp[fee-cost[meal]]+cost[meal]);
                }
            }
        }
        cout<<mon-cost[n-1]-dp[left]<<endl;
        
    }
}