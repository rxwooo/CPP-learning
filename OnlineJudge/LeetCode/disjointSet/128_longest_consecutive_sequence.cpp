#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> _map;
        int len = nums.size();
        for(int i = 0; i < len; i++)
            _map.insert({nums[i], i});
        for(int i = 0; i < len; i++)
        {
            if(_map[nums[i]] != i)
                continue;
            if(_map.find(nums[i] - 1) == _map.end())
                continue;
            _map[nums[i]] = _map[nums[i] - 1];
        }
        int longest = 0;
        for(int i = 0; i < len; i++)
        {
            if(_map[nums[i]] != i)
                continue;
            int length = 0;
            int cur = nums[i];
            while(_map.find(cur++) != _map.end())
            {
                length ++;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};

int main()
{
    vector<int> arr = {100,4,200,1,3,2};
    Solution so;
    cout << so.longestConsecutive(arr) <<  endl;
    return 0;
}