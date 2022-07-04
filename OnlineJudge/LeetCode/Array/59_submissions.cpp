#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    // edge: right, down, left, up
    vector<vector<int>> mar(n, vector<int>(n, 0));
    int right = n - 1;
    int down = n - 1;
    int left = 0;
    int up = 1;
    int count = 1;
    int i = 0;
    int j = 0;
    while (count <= n * n)
    {
        for (; j <= right; j++)
            mar[i][j] = count++;
        j = right;
        right--;
        i++;
        for (; i <= down; i++)
            mar[i][j] = count++;
        i = down;
        down--;
        j--;
        for (; j >= left; j--)
            mar[i][j] = count++;
        j = left;
        left++;
        i--;
        for (; i >= up; i--)
            mar[i][j] = count++;
        i = up;
        up++;
        j++;
    }
    return mar;
}

int main()
{
    generateMatrix(4);
    return 0;
}