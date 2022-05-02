#include <bits/stdc++.h>
using namespace std;

int numTrees(int n)
{
    int dp[21];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 2; i <= n; i ++)
    {
        int sum = 0;
        for(int j = 0; j < i; j ++)
        {
            sum += dp[j] * dp[i - j - 1];
        }
        dp[i] = sum;
    }
    return dp[n];
}

//1 2 3 4 5
//1 2 5 


int main()
{
    cout << numTrees(3) << endl;
    return 0;
}