#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> dp(4, 0);

        dp[0] = -prices[0];
        dp[2] = -prices[0];
        for(int i = 1; i < len; i++)
        {
            dp[3] = max(dp[2] + prices[i], dp[3]);
            dp[2] = max(dp[1] - prices[i], dp[2]);
            dp[1] = max(dp[0] + prices[i], dp[1]);
            dp[0] = max(-prices[i], dp[0]);
        }
        return max(dp[3], dp[1]);
    }
};

int main()
{
    
    return 0;
}