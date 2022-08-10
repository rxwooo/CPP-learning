#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while(start + 1 < end)
        {
            while(start < end && nums[start] == nums[start + 1]) start++;
            while(start < end && nums[end] == nums[end - 1]) end--;

            int mid = start + (end - start) / 2;
            if(nums[mid] == target)
                return 1;
            if(nums[end] > nums[mid])
                if(target <= nums[end] && target >= nums[mid])
                    start = mid;
                else
                    end = mid;
            else if(nums[start] < nums[mid])
                if(target <= nums[mid] && target >= nums[start])
                    end = mid;
                else
                    start = mid;
        }
        if(nums[start] == target)
            return 1;
        if(nums[end] == target)
            return 1;
        return 0;
    }
};

int main()
{
    
    return 0;
}