#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回满足题意的最小操作数
     * @param str string字符串 给定字符串
     * @return int整型
     */
    int minOperations(string str) {
        int len = str.size();
        vector<bool> alpha(26, 0);
        int count = 0;
        for(char c: str)
        {
            if(alpha[c - 'a'] == 1)
                count ++;
            alpha[c - 'a'] = !alpha[c - 'a'];
        }
        int left = len - count * 2;
        int res = count;
        int single = left + count;
        res += single - 26;
        return res;
    }
};

int main()
{
    
    return 0;
}