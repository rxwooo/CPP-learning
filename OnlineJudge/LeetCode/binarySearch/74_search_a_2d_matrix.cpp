#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row * col - 1;

        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            int r = mid / col;
            int c = mid % col;
            if(matrix[r][c] == target)
                end = mid;
            else if(matrix[r][c] < target)
                start = mid;
            else
                end = mid;
        }

        if(matrix[start/col][start%col] == target)
            return 1;
        if(matrix[end / col][end % col] == target)
            return 1;
        return 0;
    }
};

int main()
{
    Solution so;
    vector<vector<int>> test = {{1}};
    so.searchMatrix(test, 0);
    return 0;
}