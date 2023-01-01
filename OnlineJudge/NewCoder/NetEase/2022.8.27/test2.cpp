#include<bits/stdc++.h>
using namespace std;

//check four point of mar2 if in the mar1
bool intersect(vector<int>& mar1, vector<int>& mar2)
{
    //1 of 2
    //left up
    if(mar2[0] > mar1[0] && mar2[0] < mar1[2] && mar2[1] > mar1[1] && mar2[1] < mar1[3])
        return 1;
    //right up
    if(mar2[2] > mar1[0] && mar2[2] < mar1[2] && mar2[1] > mar1[1] && mar2[1] < mar1[3])
        return 1;
    //left down
    if(mar2[0] > mar1[0] && mar2[0] < mar1[2] && mar2[3] > mar1[1] && mar2[3] < mar1[3])
        return 1;
    //right down
    if(mar2[2] > mar1[0] && mar2[2] < mar1[2] && mar2[3] > mar1[1] && mar2[3] < mar1[3])
        return 1;
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<bool> chk(n);
        vector<vector<int>> mar(n, vector<int>(4));
        int maxX = 0;
        int maxY = 0;
        int res = 0;
        for(int i = 0; i < n; i ++)
        {
            cin >> mar[i][0] >> mar[i][1] >> mar[i][2] >> mar[i][3];
            maxX = max(maxX, mar[i][2]);
            maxY = max(maxY, mar[i][3]);
        }
        for(int i = 0; i < n; i ++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(chk[i] && chk[j])
                    continue;
                if(intersect(mar[i], mar[j]))
                {
                    chk[i] = 1;
                    chk[j] = 1;
                }
            }
        }
        vector<vector<bool>> _map(maxX + 1, vector<bool>(maxY + 1, 0));
        for(int i = 0; i < n; i++)
        {
            if(!chk[i])
                continue;
            for(int row = mar[i][0]; row < mar[i][2]; row++)
            {
                for(int col = mar[i][1]; col < mar[i][3]; col++)
                {
                    if(_map[row][col])
                        continue;
                    _map[row][col] = 1;
                    res ++;
                }
            }
        }
        cout << res << endl;
    } 
    return 0;
}
// 1
// 4
// 0 0 2 2
// 1 1 4 3
// 2 4 4 7
// 2 5 3 6