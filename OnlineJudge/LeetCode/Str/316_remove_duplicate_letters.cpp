#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s)
{
    unordered_map<char, int> sta;
    vector<char> _stack;
    string res = "";
    int len = s.size();
    vector<bool> vis(26, 0);
    for (int i = 0; i < len; i++)
        sta[s[i]]++;
    for (int i = 0; i < len; i++)
    {
        if (_stack.size() == 0)
        {
            _stack.push_back(s[i]);
            sta[s[i]]--;
            vis[s[i] - 'a'] = 1;
            continue;
        }
        if (vis[s[i] - 'a'] == 1)
        {
            sta[s[i]]--;
            continue;
        }
        while (_stack.back() > s[i] && sta[_stack.back()] > 0)
        {
            vis[_stack.back() - 'a'] = 0;
            _stack.pop_back();
            if (_stack.size() == 0)
                break;
        }
        _stack.push_back(s[i]);
        sta[s[i]]--;
        vis[s[i] - 'a'] = 1;
    }
    for (char c : _stack)
        res += c;
    return res;
}

int main()
{
    string test = "bbcaac";
    removeDuplicateLetters(test);
    return 0;
}