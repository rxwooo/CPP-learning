#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
{
    int dp[102][102];
    int ans[102][102];
    int rows = mat.size();
    int cols = mat[0].size();
    dp[0][0] = 0;
    for(int i = 1; i < cols; i++)
        dp[0][i] = dp[0][i - 1] + mat[0][i];
    for(int i = 1; i < rows; i++)
        dp[i][0] = dp[i - 1][0] + mat[i][0];
    for(int i = 1; i < rows; i++)
        for(int j = 1; j < cols; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
        {
            int left = j < k? dp[i][0]: dp[i][j - k];
        }
    
}

int main()
{

    return 0;
}