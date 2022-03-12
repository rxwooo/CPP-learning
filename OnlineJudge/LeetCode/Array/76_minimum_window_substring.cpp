#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> hs, ht;
        for (auto c : t)
            ht[c]++;
        string res;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            hs[s[i]]++;
            if (hs[s[i]] <= ht[s[i]])
                cnt++;

            while (hs[s[j]] > ht[s[j]])
                hs[s[j++]]--;
            if (cnt == t.size())
            {
                if (res.empty() || i - j + 1 < res.size())
                    res = s.substr(j, i - j + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution so;
    cout << so.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}