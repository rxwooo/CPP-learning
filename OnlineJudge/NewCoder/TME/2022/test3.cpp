#include <bits/stdc++.h>
using namespace std;

int minCnt(string s)
{
    int len = s.size();
    int count = 0;
    for(int i = 1; i < len; i++)
    {
        if(s[i] == '1')
            count ++;
    }
    return count;
}

int main()
{

    return 0;
}