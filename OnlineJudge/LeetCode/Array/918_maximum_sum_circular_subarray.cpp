#include<bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> copy;
        int sum = nums[0];
        int maxN = nums[0];
        int len = nums.size();
        int end = nums[len - 1];
        if(len == 1)
            return nums[0];
        else if(len == 2)
            return max(nums[0] + nums[1], max(nums[0], nums[1]));
        copy.push_back(0x3f3f3f3f);
        int minN = copy[0];
        for(int i = 1; i < len; i++)
        {
            sum += nums[i];
            copy.push_back(nums[i]);
            copy[i] = min(copy[i], copy[i] + copy[i - 1]);
            nums[i] = max(nums[i], nums[i] + nums[i - 1]);
            if(nums[i] > maxN)
                maxN = nums[i];
            if(copy[i] < minN && i != len - 1)
                minN = copy[i];
        }
        return max(maxN, sum - minN);
    }

int main()
{
    vector<int> test = {3,-2,2,-3};
    cout << maxSubarraySumCircular(test) << endl;
    return 0;
}