#include <bits/stdc++.h>
using namespace std;

int calculate(string s)
{
    int len = s.size();
    if (len == 0)
        return 0;
    vector<char> str;
    for (char c : s)
        if (c != ' ')
            str.push_back(c);
    len = str.size();
    int res = 0;
    int pos = 0;
    int bg = 0;
    int lastOpt = s[0] == '-' ? 0 : 1; // 1-add 0-sub
    while (pos < len)
    {
        while (pos < len && str[pos] != '+' && str[pos] != '-')
            pos++;
        int num = 1;
        int opt = 1; // 1-multi 0-div
        while (bg < pos)
        {
            string tpStr = "";
            while (bg < pos && str[bg] != '*' && str[bg] != '/')
                tpStr += str[bg++];
            int tpNum = stoi(tpStr);
            if (opt)
                num *= tpNum;
            else
                num /= tpNum;
            if (bg >= len)
                break;
            if (str[bg] == '/')
                opt = 0;
            else if (str[bg] == '*')
                opt = 1;
            bg++;
        }
        // if(bg == pos)
        // {
        //     pos ++;
        //     continue;
        // }
        if (lastOpt)
            res += num;
        else
            res -= num;
        if(pos >= len)
            break;
        if (str[pos] == '+')
            lastOpt = 1;
        else if (str[pos] == '-')
            lastOpt = 0;
        pos++;
    }
    return res;
}

int main()
{
    string tp = "0";
    calculate(tp);
    return 0;
}