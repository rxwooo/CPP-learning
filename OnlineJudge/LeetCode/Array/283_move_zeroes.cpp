#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void arrSwap(vector<int>& nums, int a, int b)
    {
        if(a == b) return;
        nums[a] = nums[a] ^ nums[b];
        nums[b] = nums[a] ^ nums[b];
        nums[a] = nums[a] ^ nums[b];
    }

    void moveZeroes(vector<int>& nums) {
        int nonzero = 0;       
        int pos = 0;
        while(pos < nums.size())
        {
            if(nums[pos])
            {
                arrSwap(nums, pos, nonzero);
                nonzero++;
            }
            pos++;
        }
    }
};

int main()
{
    
    return 0;
}