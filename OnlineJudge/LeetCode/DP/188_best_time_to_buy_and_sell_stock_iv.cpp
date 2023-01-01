#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0)
            return 0;
        int len = prices.size();
        vector<int> dp(2*k, 0);
        for(int i = 0; i < k; i++)
            if(i * 2 < len)
                dp[i * 2] = -prices[0];
        for(int i = 1; i < len; i++)
        {
            for(int j = 1 ; j < k; j++)
            {
                dp[j * 2 + 1] = max(dp[j * 2 + 1], dp[j * 2] + prices[i]);
                dp[j * 2] = max(dp[j * 2], dp[j * 2 - 1] - prices[i]);
            }
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[0] = max(dp[0], -prices[i]);
        }
        int maxN = dp[0];
        for(int i = 1; i < 2 * k; i++)
            maxN = max(maxN, dp[i]);
        return maxN;
    }
};

int main()
{
    
    return 0;
}