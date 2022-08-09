#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> _map;
        int len2 = nums2.size();
        for(int i = 0 ; i < len2; i++)
            _map.insert({nums2[i], i});
        stack<int> _stack;
        vector<int> res(len2, -1);
        for(int i = 0; i < len2; i++)
        {
            while(!_stack.empty() && nums2[i] > nums2[_stack.top()])
            {
                int cur = _stack.top();
                _stack.pop();
                res[cur] = nums2[i];
            }
            _stack.push(i);
        }
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++)
        {
            ans[i] = res[_map[nums1[i]]];
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}