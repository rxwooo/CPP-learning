#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> paper(n, vector<char>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> paper[i][j];
        int full = m / n;
        int margin = m % n;
        margin = margin % 2 == 0? margin: margin + n;
        int offset = n - margin / 2;
        for(int row = 0; row < m; row ++)
        {
            for(int col = 0; col < m; col ++)
            {
                cout << paper[(row + offset) % n][(col + offset) % n];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
// 1
// 3 5
// 1x1
// xox
// 1x1