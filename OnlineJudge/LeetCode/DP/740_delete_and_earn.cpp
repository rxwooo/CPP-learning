#include <bits/stdc++.h>
using namespace std;



int deleteAndEarn(vector<int> &nums)
{
    unordered_map<int, int> numsMap;
    int dp[20010];
    int len = nums.size();
    for(int i = 0; i < len; i++)
    {
        if(numsMap.find(nums[i]) == numsMap.end())
            numsMap.insert({nums[i], 1});
        else
            numsMap[nums[i]] ++;
    }
    sort(nums.begin(), nums.end());
    numsMap.insert({0, 1});
    nums.push_back(0);

    int lastOffset = numsMap[nums[len - 1]];
    dp[len] = 0;
    dp[len - 1] = lastOffset * nums[len - lastOffset];
    int offsetNow = lastOffset;
    for(int i = len - lastOffset - 1; i >= 0; )
    {
        offsetNow = numsMap[nums[i]];
        int offsetNext = numsMap[nums[i + 1]];
        if(nums[i + 1] - nums[i] > 1){
            dp[i] = nums[i] * offsetNow + dp[i + offsetNext];
        } 
        else
        {
            int offsetNext2 = numsMap[nums[i + 1 + offsetNext]];
            int re1 = dp[i + offsetNext + offsetNext2] + nums[i] * offsetNow;
            int re2 = dp[i + offsetNext];
            dp[i] = max(re1, re2);
        }
        i -= offsetNow;
    }
    return dp[offsetNow - 1];
}

int main()
{
    vector<int> test = {8,10,4,9,1,3,5,9,4,10};
    cout << deleteAndEarn(test) << endl;
    return 0;
}