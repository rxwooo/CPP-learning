#include <bits/stdc++.h>
using namespace std;

vector<int> getNext(string s)
{
    vector<int> next(s.size(), 0);
    for(int i = 1; i < s.size(); i ++)
    {
        if(s[next[i - 1]] == s[i]) 
            next[i] = next[i - 1] + 1;
        else
        {
            int tp = next[i - 1];
            while(tp != 0)
            {
                if(s[tp] == s[i])
                {
                    next[i] = tp + 1;
                    break;
                }
                tp = next[tp - 1];
                if(tp == 0)
                    next[i] = s[tp] == s[i];
            }
        }
    }
    return next;
}

int strStr(string haystack, string needle)
{
    if(needle == "") return 0;
    vector<int> nextarr = getNext(needle);
    int pos = 0;
    int subPos = 0;
    while(pos < haystack.size())
    {
        while(haystack[pos] == needle[subPos])
        {
            pos ++;
            subPos ++;
            if(subPos == needle.size())
                return pos - needle.size();
        }
        if(subPos == 0)
            pos ++;
        else subPos = nextarr[subPos - 1];
    }
    return -1;
}

int main()
{
    cout << strStr("aaaaa", "bba") << endl;
    return 0;
}