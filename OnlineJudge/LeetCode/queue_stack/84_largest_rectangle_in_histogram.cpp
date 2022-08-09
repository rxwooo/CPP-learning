#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> _stack;
        int len = heights.size();
        int area = 0;
        for(int i = 0; i < len; i ++)
        {
            while(!_stack.empty() && heights[i] < heights[_stack.top()])
            {
                int h = heights[_stack.top()];
                _stack.pop();
                int w = _stack.empty()? i: (i - _stack.top() - 1);
                area = max(area, h * w);
            }
            _stack.push(i);
        }
        return area;
    }
};

int main()
{
    
    return 0;
}