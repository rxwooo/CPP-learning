#include<bits/stdc++.h>
using namespace std;

int main()
{
    char seat[1010];
    memset(seat, 0, sizeof(seat));

    vector<vector<int>> svec;
    int count = 0;
    for(;;)
    {
        char c = getchar();
        if(c == ' ')
            continue;
        if(c == '\n')
            break;
        if(svec.size() == 0)
            svec.push_back({});
        int sz = svec.size();
        if(c == '0')
            svec[sz - 1].push_back(count);
        else
            if(svec[sz - 1].size() != 0)
                svec.push_back({});
        count++;
    }

    int sz = svec.size();
    int maxDis = 0;
    for(int i = 0; i < sz; i++)
    {
        int len = svec[i].size();
        if(len == 0)
            break;
        if(len == 1)
            len = 1;
        else if(svec[i][0] == 0 || svec[i][len - 1] == count - 1)
            len = len;
        else
            len = (len + 1) / 2;
        if(len > maxDis)
            maxDis = len;
    }

    cout << maxDis << endl;

    return 0;
}