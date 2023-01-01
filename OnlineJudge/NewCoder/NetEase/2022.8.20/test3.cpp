#include <bits/stdc++.h>
using namespace std;

int oddCount(string str)
{
    int len = str.size();
    int opE = 0;
    for (int i = 1; i < len; i += 2)
        if (str[i] != 'e')
            opE++;
    int bgR = 0;
    char last = 'd';
    for (int i = 0; i < len; i += 2)
    {
        if (str[i] == last)
            bgR++;
        last = last == 'd' ? 'r' : 'd';
    }
    int bgD = 0;
    last = 'r';
    for (int i = 0; i < len; i += 2)
    {
        if (str[i] == last)
            bgD++;
        last = last == 'd' ? 'r' : 'd';
    }
    return opE + min(bgR, bgD);
}

int main()
{
    string str;
    cin >> str;
    int res;
    int len = str.size();
    if(len == 0 || len == 1 || len == 2)
    {
        cout << 0 << endl;
        return 0;
    }
    if (len % 2 == 1)
    {
        res = oddCount(str);
    }
    else
    {
        string strCopy = str.substr(0, len - 1);
        int bg0 = oddCount(strCopy);
        strCopy = str.substr(1);
        int bg1 = oddCount(strCopy);
        res = min(bg0, bg1);
    }
    cout << res << endl;
    return 0;
}