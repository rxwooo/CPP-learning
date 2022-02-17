#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int bg[1010];
        int val[1010], wei[1010];
        int n, bag;
        memset(bg,0,sizeof(bg));
        cin >> n >> bag;

        for (int i = 1; i <= n; i++)
            cin >> val[i];
        for (int i = 1; i <= n; i++)
            cin >> wei[i];

        for (int i = 1; i <= n; i++)
            for (int j = bag; j >= wei[i]; j--)
                bg[j] = max(bg[j], bg[j - wei[i]] + val[i]);

        cout<<bg[bag]<<endl;
    }
}