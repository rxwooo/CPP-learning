#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.length() == 0)
            return 0;
        stack<char> charStack;
        charStack.push(s[0]);
        int len = s.length();
        for (int i = 1; i < len; i++)
        {
            char cur = s[i];
            if (charStack.size() == 0)
            {
                charStack.push(s[i]);
                continue;
            }
            char last = charStack.top();
            switch (s[i])
            {
            case '}':
                if (last == '{')
                    charStack.pop();
                else
                    return 0;
                break;
            case ']':
                if (last == '[')
                    charStack.pop();
                else
                    return 0;
                break;
            case ')':
                if (last == '(')
                    charStack.pop();
                else
                    return 0;
                break;

            default:
                charStack.push(s[i]);
            }
        }
        if (charStack.size() == 0)
            return 1;
        return 0;
    }
};

int main()
{

    return 0;
}