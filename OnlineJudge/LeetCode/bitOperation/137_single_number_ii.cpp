#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            int tp = 0;
            for(int j = 0; j < nums.size(); j++)
                tp += ((nums[j] >> i) & 1);
            tp %= 3;
            if(tp != 0)
                res += (1 << i);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}