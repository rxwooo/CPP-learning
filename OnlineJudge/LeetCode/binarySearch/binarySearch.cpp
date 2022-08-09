#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size() - 1;
        int start = 0;

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
        if(nums[start] == target)
            return start;
        if(nums[end] == target)
            return end;
        return -1;
    }
};

int main()
{
    
    return 0;
}