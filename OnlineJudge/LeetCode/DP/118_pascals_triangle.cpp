#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    ans.push_back({1});
    if(numRows == 1)
        return ans;
    ans.push_back({1, 1});
    for (int i = 2; i < numRows; i++)
    {
        int len = ans.size();
        ans.push_back({1});
        for (int j = 0; j < ans[len - 1].size() - 1; j++)
            ans[len].push_back(ans[len - 1][j] + ans[len - 1][j + 1]);
        ans[len].push_back(1);
    }
    return ans;
}

int main()
{
    generate(5);
    return 0;
}