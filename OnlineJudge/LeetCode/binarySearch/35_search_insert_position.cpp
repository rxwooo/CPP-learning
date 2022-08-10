#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target)
                end = mid;
            else if(nums[mid] < target)
                start = mid;
            else
                end = mid;
        }

        if(nums[start] >= target)
            return start;
        if(nums[end] < target)
            return end + 1;
        return end;
    }
};

int main()
{
    
    return 0;
}