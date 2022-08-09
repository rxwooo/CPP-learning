#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) 
    { 
        stack<int> cstack;
        int len = s.length();
        if(len == 0 || len == 1)
            return 0;
        for(int i = 0; i < len; i++)
        {
            if(cstack.size() == 0)
            {
                cstack.push(i);
                continue;
            }
            int c = cstack.top();
            if(s[c] == '(' && s[i] == ')')
                cstack.pop();
            else
                cstack.push(i);
        }
        if(cstack.size() == 0)
            return len;
        int R = len;
        int L = 0;
        int maxDis = 0;
        while(cstack.size() != 0)
        {
            L = cstack.top();
            if(R - L != 1)
            {
                int dis = R - L - 1;
                if(dis > maxDis)
                    maxDis = dis;
            }
            cstack.pop(); 
            R = L; 
        }
        if(R != 0)
            maxDis = max(maxDis, R);
        return maxDis;
    }
};
int main()
{
    Solution so;
    cout << so.longestValidParentheses("())") << endl;
    return 0;
}