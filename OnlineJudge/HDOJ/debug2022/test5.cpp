#include <bits/stdc++.h>
using namespace std;

int countS(string str, int num)
{
    int ans = 0;
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        int c = str[i];
        c -= '0';
        ans = ans + c;
        ans = (ans * 10) % num;
    }
    return ans;
}

int main()
{
    int ans[1010];
    string n;
    int m;
    cin >> n >> m;
    int len = n.size();
    for (int i = 0; i < len; i++)
        ans[i] = n[i] - '0';
    for (int i = 0; i < len; i++)
        ans[i + 1] = (ans[i] * 10 + ans[i + 1]) % m;
    cout << ans[len - 1] << endl;

    return 0;
}