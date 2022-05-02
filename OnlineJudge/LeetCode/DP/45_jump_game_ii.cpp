#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    int dp[10010];
    int len = nums.size();
    dp[len - 1] = 0;
    nums[len - 1] = 2000;
    for(int i = len - 2; i >= 0; i--)
    {
        if(nums[i] >= dp[i + 1])
            dp[i] = 1 + dp[i + dp[i + 1]];
    }
    
    return dp[0];
}

int main()
{
    vector<int> test = {2, 3, 0, 1, 4};
    cout << jump(test) << endl;
    return 0;
}