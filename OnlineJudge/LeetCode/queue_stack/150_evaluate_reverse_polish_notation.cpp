#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int str2Int(string str)
    {
        int res = 0;
        int len = str.size();
        for(int i = len - 1; i >= 0; i--)
        {
            if(str[i] == '-')
                res = -res;
            else
                res += (str[i] - '0') * pow(10, len - i - 1);
        }
        return res;
    }

    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        stack<int> _stack;
        for(int i = 0; i < len; i ++)
        {
            if(tokens[i].size() > 1 || _stack.size() < 2)
                _stack.push(str2Int(tokens[i]));
            else
            {
                if(tokens[i][0] >= '0' && tokens[i][0] <= '9')
                    _stack.push(tokens[i][0] - '0');
                else
                {
                    int b = _stack.top();
                    _stack.pop();
                    int a = _stack.top();
                    _stack.pop();

                    if(tokens[i][0] == '+')
                        _stack.push(a + b);
                    else if(tokens[i][0] == '-')
                        _stack.push(a - b);
                    else if(tokens[i][0] == '*')
                        _stack.push(a * b);
                    else if(tokens[i][0] == '/')
                        _stack.push(a / b);
                }
            }
        }
        return _stack.top();
    }
};

int main()
{
    Solution so;
    vector<string> test = {"18"};
    int outcome = so.evalRPN(test);
    return 0;
}