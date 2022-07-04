#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int rows = triangle.size();
    for(int i = rows - 2;  i >= 0; i--)
        for(int j = 0; j <= i; j++)
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
    return triangle[0][0];
}

int main()
{

    return 0;
}