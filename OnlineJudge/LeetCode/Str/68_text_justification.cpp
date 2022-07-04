#include <bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    int len = words.size();
    vector<string> ans;
    int pos = 0;    //当前遍历位置
    int count = 0;  //该行数量
    int curLen = 0; //当前最少长度
    ans.push_back("");
    while (pos < len)
    {
        if (curLen + words[pos].size() < maxWidth)
        {
            curLen += words[pos].size();
            curLen++;
            count++;
            pos++;
            continue;
        }
        else if (curLen + words[pos].size() == maxWidth)
        {
            for (int i = 0; i < count; i++)
                ans.back() += words[pos - count + i] + " ";
            ans.back() += words[pos];
            pos++;
        }
        else
        {
            int space = maxWidth - curLen + count;
            if (count == 1)
            {
                ans.back() += words[pos - count];
                ans.back().append(space, ' ');
            }
            else
            {
                int more = space % (count - 1);
                space = space / (count - 1);
                for (int i = 0; i < count - 1; i++)
                {
                    ans.back() += words[pos - count + i];
                    ans.back().append(space, ' ');
                    if (more-- > 0)
                        ans.back() += ' ';
                }
                ans.back() += words[pos - 1];
            }
        }
        ans.push_back("");
        count = 0;
        curLen = 0;
    }
    if (count > 0)
    {
        for (int i = 0; i < count; i++)
            ans.back() += words[pos - count + i] + " ";
        ans.back().append(maxWidth - curLen, ' ');
    }
    else
        ans.pop_back();
    return ans;
}

int main()
{
    vector<string> test = {"This", "is", "an", "example", "of", "text", "justification."};
    fullJustify(test, 16);
    return 0;
}