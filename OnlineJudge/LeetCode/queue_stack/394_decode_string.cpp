#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int len = s.size();
        stack<char> tp;
        deque<char> deq;
        string res;
        for(int i = 0 ; i< len; i++)
        {
            if(s[i] != ']')
                deq.push_back(s[i]);
            else
            {
                char c = deq.back();
                while(c != '[')
                {
                    deq.pop_back();
                    tp.push(c);
                    c = deq.back();
                }
                deq.pop_back();

                int digit = 0;
                int k = 0;
                char num = deq.back();
                while(num >= '0' && num <= '9')
                {
                    k += (deq.back() - '0') * pow(10, digit++);
                    deq.pop_back();
                    if(deq.empty())
                        break;
                    num = deq.back();
                }

                string tpStr;
                while(tp.size() != 0)
                {
                    tpStr += tp.top();
                    tp.pop();
                }
                
                while(k--)
                    for(int i = 0; i < tpStr.size(); i++)
                        deq.push_back(tpStr[i]);
            }
        }
        while(deq.size())
        {
            res += deq.front();
            deq.pop_front();
        }
        return res;
    }
};

int main()
{
    Solution so;
    string str = "3[a]2[bc]";
    cout << so.decodeString(str) << endl;
    return 0;
}