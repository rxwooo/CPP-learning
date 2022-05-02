#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    bool dp[50010];
    int sum = 0;
    int len = prices.size();
    int curmin = prices[0];
    int curmax = 0;
    memset(dp, 0, sizeof(dp));
    dp[len - 1] = 1;
    for (int i = len - 1; i > 0; i--)
    {
       if (prices[i] - curmax > fee)
        {
            dp[i] = 1;
            curmax = prices[i - 1];
        }
    }
    for (int i = 1; i < len; i++)
    {
        if (prices[i] - curmin > fee && dp[i] == 1)
        {
            sum += prices[i] - curmin - fee;
            curmin = prices[i];
        }
        if (curmin > prices[i])
            curmin = prices[i];
    }
    return sum;
}

int main()
{
    vector<int> test = {1,3,2,8,4,9};
    cout << maxProfit(test, 2) << endl;
    return 0;
}