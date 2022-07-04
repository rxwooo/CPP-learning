#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i = rows - 2; i >= 0; i--)
    {
        for(int j = 0; j < cols; j++)
        {
            if(j == 0) 
                matrix[i][j] += min(matrix[i + 1][j], matrix[i + 1][j + 1]);
            else if(j == cols - 1) 
                matrix[i][j] += min(matrix[i + 1][j], matrix[i + 1][j - 1]);
            else 
                matrix[i][j] += min(matrix[i + 1][j], min(matrix[i + 1][j - 1], matrix[i + 1][j + 1]));
        }
    }
    int maxN = 0x3f3f3f3f;
    for(int i = 0; i < cols; i ++)
        if(matrix[0][i] < maxN)
            maxN = matrix[0][i];
    return maxN;
}

int main()
{

    return 0;
}