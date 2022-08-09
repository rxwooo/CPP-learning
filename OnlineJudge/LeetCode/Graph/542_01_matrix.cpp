#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        queue<vector<int>> qu;
        int h = mat.size();
        int w = mat[0].size();
        vector<vector<int>> res(h, vector<int>(w));

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (mat[i][j] == 0)
                    qu.push({i, j});

        vector<vector<int>> move = {{0, 0, 1, -1}, {1, -1, 0, 0}};
        int len = move[0].size();
        while (qu.size())
        {
            vector<int> cur = qu.front();
            qu.pop();
            for (int i = 0; i < len; i++)
            {
                int row = cur[0] + move[0][i];
                int col = cur[1] + move[1][i];
                if (row >= 0 && row < h && col >= 0 && col < w)
                    if (mat[row][col] && !res[row][col])
                    {
                        qu.push({row, col});
                        res[row][col] = res[cur[0]][cur[1]] + 1;
                    }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    Solution so;
    so.updateMatrix(mat);
    return 0;
}