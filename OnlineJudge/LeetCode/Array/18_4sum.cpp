#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int newTarget = target - nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int nowTarget = newTarget - nums[j];
            int l = j + 1;
            int r = nums.size() - 1;
            while (r > l)
            {
                if (l > j + 1 && nums[l] == nums[l - 1])
                {
                    l++;
                    continue;
                }
                if (r < nums.size() - 1 && nums[r] == nums[r + 1])
                {
                    r--;
                    continue;
                }
                int re = nums[l] + nums[r];
                if (nowTarget == re)
                    ans.push_back({nums[i], nums[j], nums[l++], nums[r--]});
                if(re > nowTarget)
                    r--;
                if(re < nowTarget)
                    l++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {1,-2,-5,-4,-3,3,3,5};
    vector<vector<int>> vec2 = fourSum(vec, -11);
    for (int i = 0; i < vec2.size(); i++)
        for (int j = 0; j < 4; j++)
            cout << vec2[i][j] << endl;
    return 0;
}