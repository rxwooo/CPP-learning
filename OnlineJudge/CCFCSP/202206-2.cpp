#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int l, s;
    cin >> l >> s;
    vector<vector<bool>> _map(l + 1, vector<bool>(l + 1, 0));
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        _map[x][y] = 1;
    }
    vector<vector<bool>> _sMap(s + 1, vector<bool>(s + 1, 0));
    for (int i = s; i >= 0; i--)
        for (int j = 0; j <= s; j++)
        {
            int num;
            cin >> num;
            _sMap[i][j] = num;
        }
    int res = 0;
    for (int i = s; i <= l; i++)
    {
        for (int j = s; j <= l; j++)
        {
            int x = 0;
            int flag = 1;
            while (x <= s)
            {
                int y = 0;
                while (y <= s)
                {
                    if(_sMap[x][y] == _map[i - s + x][j - s + y])
                    {
                        y ++;
                        continue;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                x ++;
                if(!flag)
                    break;
            }
            if(flag)
                res ++;
        }
    }
    cout << res << endl;
    return 0;
}