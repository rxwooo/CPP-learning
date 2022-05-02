#include <bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int> &nums)
{
    int len = nums.size();
    int count = 1;
    int lastDif = 10000;
    int re = 0;
    for(int i = 1; i < len; i++)
    {
        int tp = nums[i] - nums[i - 1];
        if(tp == lastDif)
            count ++;
        else
            count = 1;
        
        if(count > 1)
            re += count - 1;
        lastDif = tp;
    }
    return re;
}

int main()
{
    vector<int> test = {1, 2, 3, 4};
    cout << numberOfArithmeticSlices(test) << endl;
    return 0;
}