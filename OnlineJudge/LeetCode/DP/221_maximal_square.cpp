#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int dp[302][302];
    memset(dp, 0, sizeof(dp));
    int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1] - '0';
            if (matrix[i - 1][j - 1] == '1')
                count++;
        }

    if (count == 0)
        return 0;
    int minN = min(row, col);
    for (int i = 2; i <= minN; i++)
    {
        count = 0;
        for (int r = i; r <= row; r++)
            for (int c = i; c <= col; c++)
                if (dp[r][c] - dp[r][c - i] - dp[r - i][c] + dp[r - i][c - i] == i * i)
                    count++;
        if (count == 0)
            return (i - 1) * (i - 1);
    }
    return minN;
}

int main()
{
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << maximalSquare(matrix) << endl;
    return 0;
}