#include <bits/stdc++.h>
using namespace std;

void outputColor(string color)
{
    if(color == "#R")
        cout << " " << "FF0000" << endl;
    else if(color == "#G")
        cout << " " << "00C923" << endl;
    else if(color == "#B")
        cout << " " << "0000FF" << endl;
    else if(color == "#K")
        cout << " " << "000000" << endl;
    else if(color == "#Y")
        cout << " " << "FFFF00" << endl;
    else if(color == "#P")
        cout << " " << "FF88FF" << endl;
    else
        cout << " " << color.substr(2, 6)<< endl;
}

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string str;
        stack<string> color;
        stack<int> colorPos;
        int resCount = 0;
        char c;
        while (1)
        {
            c = getchar();
            if (c == '\n')
                break;
            str += c;
        }
        int pos = 0;
        int len = str.size();
        if(str.substr(len - 2, 2) != "#n")
            str += "#n";
        for(pos = 0 ; pos < len; pos++)
            if(str[pos] == '#' && pos + 1 < len)
            {
                string subs = str.substr(pos, 2);
                if(subs == "#R" || subs == "#G" || subs == "#B" || subs == "#K" || subs == "#Y" || subs == "#P")
                {
                    color.push(subs);
                    colorPos.push(pos + 2);
                }
                if(subs == "#n")
                {
                    if(color.empty())
                        continue;
                    int lastPos = colorPos.top();
                    string resSub = str.substr(lastPos, pos - lastPos);
                    resCount ++;
                    cout << resSub;
                    resSub = color.top();
                    color.pop();
                    outputColor(resSub);
                }
                if(subs == "#C")
                {
                    if(pos + 7 >= len)
                        continue;
                    int count = 0;
                    for(int i = 1; i <= 6 ; i++)
                        if((str[pos + 1 + i] >= '0' && str[pos + 1 + i] <= '9') || (str[pos + 1 + i] >= 'A' && str[pos + 1 + i] <= 'F'))
                            count ++;
                    if(count < 6)
                        continue;
                    subs = str.substr(pos, 8);
                    color.push(subs);
                    colorPos.push(pos + 8);
                }
            }
    }
    return 0;
}
