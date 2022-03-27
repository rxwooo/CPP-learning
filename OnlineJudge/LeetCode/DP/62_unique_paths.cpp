#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int uniquePaths(int m, int n) {
        int dp[110][110];

        memset(dp, 0, sizeof(0));
        for(int i = 0; i < m; i++)
            dp[i][n - 1] =  1;
        for(int i = 0; i < n; i++)
            dp[m - 1][i] = 1;
        for(int i = m - 2; i >= 0; i --)
            for(int j = n - 2; j >= 0; j --)
                dp[i][j] = dp[i][j + 1] + dp[i + 1][j];
        return dp[0][0];
    }
};

int main()
{
    Solution so;
    cout << so.uniquePaths(3, 7) << endl; 
    return 0;
}