#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> myvec;
        int len = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; i++)
        {
            if(nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = 0 - nums[i];
            int l = i + 1;
            int r = len - 1;            
            while(r > l)
            {
                if(l > i + 1 && nums[l] == nums[l - 1])
                {
                    l++;
                    continue;
                }
                if(r < len - 1 && nums[r] == nums[r + 1])
                {
                    r--;
                    continue;
                }
                int re = nums[l] + nums[r];
                if(re == target)
                {
                    myvec.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                if(re > target)
                    r--;
                if(re < target)
                    l++;
            }
        }
        return myvec;
    }
};

int main()
{
    Solution so;
    vector<int> vec = {0, 0, 0, 0};
    vector<vector<int>> vec2 = so.threeSum(vec);
    for (int i = 0; i < vec2.size(); i++)
        for (int j = 0; j < 3; j++)
            cout << vec2[i][j] << endl;
    return 0;
}