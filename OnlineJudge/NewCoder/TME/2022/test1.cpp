#include <bits/stdc++.h>
using namespace std;

int dp [1010][510];

//n 字符串长度
//k 连续段个数
int numsOfStrings(int n, int k)
{
    for(int i = 2; i <= n; i++) 
        dp[i][1] = 26;
    for(int i = 2; i <= n; i++)
    {
        for(int j = i/2; j <k; j++)
        {
            
        }
    }
}

int main()
{

    return 0;
}