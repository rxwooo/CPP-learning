#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    int len = nums.size();
    nums.push_back(0);
    if (len == 1)
        return nums[0];
    else if (len == 2)
        return max(nums[0], nums[1]);
    int dp[110];
    int last;
    dp[0] = 0;
    dp[1] = nums[0];
    dp[2] = nums[1];
    for (int i = 3; i < len; i++)
        dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
    last = dp[len - 1];
    dp[1] = 0;
    dp[2] = nums[1];
    for (int i = 3; i <= len; i++)
        dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
    return max(dp[len], last);
}

int main()
{
    vector<int> test = {2, 3, 2};
    cout << rob(test) << endl;
    return 0;
}