#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p)
{
    bool dp[22][42];
    
    int slen = s.size();
    int plen = p.size();
    for(int i = slen - 1; i >= 0; i++)
    {
        for(int j = plen - 1; j >= 0; j++)
        {
            if(s[i] == p[j])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                if(p[j] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                if(p[j] == '*')
                    
            }
        }
    }
}

int main()
{

    return 0;
}