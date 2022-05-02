#include <bits/stdc++.h>
using namespace std;

bool dp[302];

bool chk(string &sub, vector<string> &wordDict)
{
    int len = wordDict.size();
    for(int i = 0; i < len; i++)
        if(sub == wordDict[i])
            return 1;
    return 0; 
}

bool wordBreak(string s, vector<string> &wordDict)
{
    memset(dp, 0, sizeof(dp));
    int len = s.size();
    int re = 0;
    for(int i = 0; i < len; i++)
    {
        for(int j = i + 1; j <= len; j++)
        {
            string sub = s.substr(i,j - i);
            if(i == 0)
                dp[j] = chk(sub, wordDict);
            else if(chk(sub ,wordDict))
                dp[j] = dp[j] ? 1: dp[i] && chk(sub ,wordDict);
        }
    }
    return dp[len];
}

int main()
{
    vector<string> wordDict = {"aaaa","aaa"};
    string test = "aaaaaaa";
    cout << wordBreak(test, wordDict) << endl;
    return 0;
}
// "catsandog"
// ["cats","dog","sand","and","cat"]

// "applepenapple"
// ["apple","pen"]


// "leetcode"
// ["leet","code"]

// "aaaaaaa"
// ["aaaa","aaa"]