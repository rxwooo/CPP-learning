#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    string newstr = "#";
    string restr = "";
    int lens = s.size();
    int longest = 0;
    int pos = 0;
    int count = 0;
    for (int i = 0; i < lens; i++)
    {
        newstr += s[i];
        newstr += "#";
    }
    for (int i = 1; i < lens * 2; i++)
    {
        count = 0;
        for (int j = 0; j < lens * 2; j++)
        {
            if (i - j < 0 || j + i > lens * 2)
                break;
            if (newstr[i + j] != newstr[i - j])
                break;
            count = j;
        }
        if (count > longest)
        {
            longest = count;
            pos = i;
        }
    }
    int bg = pos - longest;
    int ed = pos + longest;
    for (int i = bg; i <= ed; i++)
        if (newstr[i] !=  '#')
            restr += newstr[i];
    return restr;
}

int main()
{
    string test = "a";
    cout << longestPalindrome(test) << endl;
    return 0;
}