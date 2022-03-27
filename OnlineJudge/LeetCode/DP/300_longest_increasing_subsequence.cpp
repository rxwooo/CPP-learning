#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[2510][2510];

    int getLength(vector<int>& nums, int L, int R)
    {
        if(L == R)
            return 1;
        
        int ck = 0;
        if(nums[L] < nums[R])
            ck = 1;
        int p1 = dp[L + 1][R] + ck;
        int p2 = dp[L][R - 1] + ck;
        dp[L][R] = max(p1, p2);
        return dp[L][R];
    }

    int lengthOfLIS(vector<int>& nums) {
        return getLength(nums, 0, nums.size() - 1);

        // int len = nums.size();
        // int dp[2510][2510];
        // memset(dp, 0, sizeof(dp));
        // for(int i = 0; i < len; i++)
        //     dp[i][i] = 1;
        // for(int i = len - 2; i >= 0; i--)
        //     for(int j = i - 1; j < len; j++)
        //     {
        //         int ck = nums[i] < nums[j];
        //         int p1 = dp[i + 1][j] + ck;
        //         int p2 = dp[i][j - 1] + ck;
        //         dp[i][j] = max(p1, p2);
        //     }
        // return dp[0][len - 1];
    }
};

int main()
{
    Solution so;
    vector<int> vec = {0,1,0,3,2,3};
    cout << so.lengthOfLIS(vec) << endl;
    return 0;
}