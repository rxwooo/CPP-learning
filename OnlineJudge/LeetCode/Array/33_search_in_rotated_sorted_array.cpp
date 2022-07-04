#include <bits/stdc++.h>
using namespace std;

int find(int target, int l, int r, vector<int> &nums)
{
    if (r < l)
        return -1;
    int mid = l + (r - l) / 2;
    if (nums[mid] == target)
        return mid;
    if (target > nums[mid])
    {
        if(target <= nums[r] || nums[mid] >= nums[l])
            return find(target, mid + 1, r, nums);
        return find(target, l, mid - 1, nums);
    }
    if(target >= nums[l] || nums[mid] <= nums[r])
        return find(target, l, mid - 1, nums);
    return find(target, mid + 1, r, nums); 
}
int search(vector<int> &nums, int target)
{
    return find(target, 0, nums.size() - 1, nums);
}

int main()
{
    vector<int> test = {4,5,6,7,8,1,2,3};
    search(test, 8);
    return 0;
}