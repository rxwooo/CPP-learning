#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int LtoR[20010];
    int RtoL[20010];
    int len = height.size();
    LtoR[0] = height[0];
    RtoL[len - 1] = height[len - 1];
    int sum = 0;
    for(int i = 1; i < len; i ++)
    {
        LtoR[i] = max(height[i], LtoR[i - 1]);
        RtoL[len - i - 1] = max(height[len - i - 1], RtoL[len - i]);
    }
    for(int i = 0; i < len ; i++)
    {
        sum += min(LtoR[i], RtoL[i]) - height[i];
    }
    return sum;
}

int main()
{
    vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(test) << endl;
    return 0;
}