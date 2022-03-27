#include<bits/stdc++.h>
using namespace std;

void generateNextarr(string& str, vector<int>& vec)
{
    int len = str.length();
    if(len == 0)
        return ;
    if(len >= 1)
        vec.push_back(0);
    for(int i = 1; i < len; i++)
    {
        int count = 0;
        while(1)
        {
            if(count + 1 == i)
                break;
            if(str.substr(0, count + 1) == str.substr(i - count - 1, count + 1))
                count ++;
            else
                break;
        }
        vec.push_back(count);
    }
}

int main()
{
    vector<int> vec;
    string str = "ll";
    generateNextarr(str, vec);
    
    string tarStr = "hello";
    int len = tarStr.length();
    int flag = 0;
    int pos = 0;
    for(int i = 0; i < len; i++)
    {
        if(pos == str.length())
        {
            cout << i - len << endl;
            return 0;
        }
        if(tarStr[i] == str[pos])
            pos++;
        else
            pos = vec[pos];
    }
    cout << -1 << endl;
    return 0;
}