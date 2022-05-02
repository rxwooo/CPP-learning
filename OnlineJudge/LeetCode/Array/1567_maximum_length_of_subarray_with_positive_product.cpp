#include<bits/stdc++.h>
using namespace std;

int getMaxLen(vector<int>& nums) {
        vector<int> zero;
        int len = nums.size();
        for(int i = 0; i < len; i++)
            if(nums[i] == 0)
                zero.push_back(i);
        int pos = 0;
        int maxLen = 0;
        zero.push_back(len);
        int zlen = zero.size();
        for(int i = 0; i < zlen; i++)
        {
            int ed = -1;
            int bg = -1;
            int count = 0;
            for(int j = pos; j < zero[i]; j++)
            {
                if(nums[j] < 0)
                {
                    count ++;
                    if(bg == -1)
                        bg = ed = j;
                    ed = j;
                }
            }
            int cur;
            if(count % 2 == 1)
                cur = max(ed - pos, zero[i] - bg - 1);
            else
                cur = zero[i] - pos;
            if(cur > maxLen)
                maxLen = cur;
            pos = zero[i] + 1;
        }
        return maxLen;
    }

int main()
{
    vector<int> test = {1,-2,-3,4};
    cout << getMaxLen(test) << endl;
    return 0;
}