#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    nums.push_back(0);
    int len = nums.size();
    if (len == 2)
        return nums[0];
    int dp[110];
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= len; i++)
        dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
    return dp[len];
}

int main()
{
    vector<int> test = {2, 1, 1, 2};
    cout << rob(test) << endl;
    return 0;
}