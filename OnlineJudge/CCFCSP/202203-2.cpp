#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<int, vector<int>> items;
    vector<int> start(100005, 0);
    int count = 1;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        items.insert({count, {a, b}});
        // for (int i = a; i > a - b; i--)
        // {
        //     if (i < 0 || start[i])
        //         break;
        //     start[i] = count;
        // }
        count++;
    }
    while (m--)
    {
        int q;
        cin >> q;
        //int todo = start[q + k];
        int res = count - 1;
        for (int i = 1; i < count; i++)
        {
            if(q + k > items[i][0])
            {
                res --;
                continue;
            }
            if (q + k + (items[i][1] - 1) < items[i][0])
                res--;
        }
        cout << res << endl;
    }
    return 0;
}