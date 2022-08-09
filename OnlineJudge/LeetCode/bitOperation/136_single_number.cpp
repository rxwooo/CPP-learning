#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        for(int i = 1; i < nums.size(); i++)
            nums[i] ^= nums[i - 1]; 
        return nums.back();
    }
};

int main()
{
    
    return 0;
}