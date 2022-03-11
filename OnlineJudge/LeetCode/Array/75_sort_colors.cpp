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
    void sortColors(vector<int>& nums) {
        int less = 0;       
        int lar = nums.size();
        int pos = 0;
        while(pos < lar)
        {
            if(nums[pos] == 0)
            {
                arrSwap(nums, pos, less);
                less++;
            }
            if(nums[pos] == 2)
            {
                lar --;
                arrSwap(nums, pos, lar);
                continue;
            }
            pos++;
        }
    }
};

int main()
{
    
    return 0;
}