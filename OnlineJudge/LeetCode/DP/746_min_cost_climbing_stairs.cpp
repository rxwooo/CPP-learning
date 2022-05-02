#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int dp[1010];
    int len = cost.size();
    cost.push_back(0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i <= len; i++)
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    return dp[len];
    // dp[i] = min(dp[i-1], dp[i-2] + cost[i])
}

int main()
{
    vector<int> test = {10, 15, 20};
    cout << minCostClimbingStairs(test) << endl;
    return 0;
}