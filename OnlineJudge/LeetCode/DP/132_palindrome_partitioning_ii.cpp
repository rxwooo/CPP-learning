#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        string str = "#";
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            str += s[i];
            str += "#";
        }
        len = str.size();
        vector<int> dp(len);
        for(int i = 0 ; i < len; i++)
            dp[i] = i;
        for(int i = 0; i < len; i++)
        {
            int offset = 1;
            while(i - offset >= 0 && i + offset < len)
            {
                dp[i - offset] = i;
                dp[i + offset] = i;
                offset ++;
            }
        }
        int count = 0;
        for(int i = 0; i < len; i++)
            if(str[i] != '#' && dp[i] != i)
                count ++;
        return s.size() - count;
    }
};


int main()
{
    Solution so;
    cout << so.minCut("123") << endl;
    return 0;
}