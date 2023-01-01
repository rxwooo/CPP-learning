#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<long long>> dp(row, vector<long long>(col, 0));
        dp[row - 1][col - 1] = !obstacleGrid[row - 1][col - 1];

        for(int i = row - 2; i >= 0; i --)
            if(!obstacleGrid[i][col - 1])
                dp[i][col - 1] = dp[i + 1][col - 1];
        
        for(int i = col - 2; i >= 0; i--)
            if(!obstacleGrid[row - 1][i])
                dp[row - 1][i] = dp[row - 1][i + 1];
        
        for(int i = row - 2; i >= 0; i--)
            for(int j = col - 2; j >= 0; j--)
                if(!obstacleGrid[i][j])
                    dp[i][j] += dp[i + 1][j] + dp[i][j + 1];
        
        return dp[0][0];
    }
};

int main()
{
    
    return 0;
}