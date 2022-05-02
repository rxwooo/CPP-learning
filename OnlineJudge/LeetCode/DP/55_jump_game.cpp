#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int dp[30010];
    int len = nums.size();
    int last = len - 1;
    for(int i = len - 1; i >= 0; i--)
        if(last - i <= nums[i])
            last = i;
    return last == 0;
}

int main()
{
    vector<int> test = {3, 2, 1, 0, 4};
    cout << canJump(test) << endl;
    return 0;
}