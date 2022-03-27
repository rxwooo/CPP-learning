#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generateNextarr(string &str, vector<int> &vec)
    {
        int len = str.length();
        if (len == 0)
            return;
        if (len >= 1)
            vec.push_back(-1);
        if (len >= 2)
            vec.push_back(0);
        for (int i = 2; i < len; i++)
        {
            int pos = vec[i - 1];
            if(str[pos] == str[i - 1])
                vec.push_back(pos+1);
            else
            {
                int tp = i - 1;
                while(pos >= 0)
                {
                    pos = vec[tp];
                    if(str[pos] == str[i - 1])
                    {
                        vec.push_back(pos + 1);
                        break;
                    }
                    if(pos == 0)
                        vec.push_back(0);
                    tp = pos;
                }
            }
        }
    }

    int strStr(string haystack, string needle)
    {
        if (needle == "")
            return 0;

        vector<int> vec;
        generateNextarr(needle, vec);
        int len = haystack.length();
        int flag = 0;
        int pos = 0;
        for (int i = 0; i < len;)
        {
            if (pos == needle.length())
                return i - needle.length();
            if(haystack[i] == needle[pos])
            {
                i++;
                pos++;
            }
            else if (vec[pos] == -1)
                i++;
            else
                pos = vec[pos];
                
        }
        if(pos == needle.length())
            return len - needle.length();
        return -1;
    }
};

int main()
{
    Solution so;
    int tp = so.strStr("mississippi","mississippi");
    cout << tp << endl;
    return 0;
}