#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int tp1 = 0;
        int tp2 = 0;
        for (int num : nums)
            tp1 ^= num;
        int bit = 0;
        for (int i = 0; i < 32; i++)
            if ((tp1 >> i) & 1)
            {
                bit = i;
                break;
            }
        for (int num : nums)
            if ((num >> bit) & 1)
                tp2 ^= num;
        tp1 ^= tp2;
        return {tp1, tp2};
    }
};

int main()
{

    return 0;
}