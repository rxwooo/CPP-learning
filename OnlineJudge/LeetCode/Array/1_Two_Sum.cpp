#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        vec.push_back(0);
        vec.push_back(0);
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    vec[0] = i;
                    vec[1] = j;
                }
            }
        }
        return vec;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        unordered_map<int, int> numset;

        vec.push_back(0);
        vec.push_back(0);

        for(int i = 0; i < nums.size(); i++)
        {
            numset.insert({nums[i], i});
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(numset.find(target - nums[i]) != numset.end())
            {
                if(i == numset[target - nums[i]])
                    continue;
                vec[0] = i;
                vec[1] = numset[target - nums[i]];
            }
        }
        return vec;
    }
};

int main()
{
    Solution2 so;
    vector<int> vec = {2,4,11,3};
    vector<int> vec2 = so.twoSum(vec, 6);
    for(int i = 0; i < 2; i++)
        cout << vec2[i] << endl;
    return 0;
}