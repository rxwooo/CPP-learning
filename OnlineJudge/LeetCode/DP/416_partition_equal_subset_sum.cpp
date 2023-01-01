#include<bits/stdc++.h>
using namespace std;

// 01背包，将sum/2作为背包上限，遍历判断能否正好填满背包

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums)
            sum += num;
        if((sum / 2) * 2 != sum)
            return 0;
        sum /= 2;

        vector<int> dp(sum + 1, 0);
        for(int num: nums)
            for(int i = sum; i >= num; i--)
                dp[i] = max(dp[i], dp[i - num] + num);

        if(dp[sum] == sum)
            return 1;
        return 0;
    }
};

int main()
{
    
    return 0;
}