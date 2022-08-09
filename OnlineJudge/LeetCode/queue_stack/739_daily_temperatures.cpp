#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> res(len, 0);
        stack<int> _stack;
        for(int i = 0; i < len; i ++)
        {
            while(!_stack.empty() && temperatures[i] > temperatures[_stack.top()])
            {
                int cur = _stack.top();
                res[cur] = i - cur;
                _stack.pop();
            }
            _stack.push(i);
        }
        return res;
    }
};

int main()
{
    
    return 0;
}