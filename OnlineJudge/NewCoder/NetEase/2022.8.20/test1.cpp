#include<bits/stdc++.h>
using namespace std;

int dfs(string a, string b, int step)
{
    if(b == "" || a == "")
        return 1000000001;
    int aNum = stoi(a);
    int bNum = stoi(b);
    if(aNum % bNum == 0 || bNum % aNum == 0)
        return step;
    int minS = 1000000001;
    for(int i = 0; i < a.size(); i++)
    {
        int res = dfs(a.erase(i, 1), b, step + 1);
        minS = min(res, minS);
    }
    for(int i = 0; i < b.size(); i++)
    {
        int res = dfs(a, b.erase(i, 1), step + 1);
        minS = min(res, minS);
    }
    return minS;
}

int main()
{
    string a, b;
    cin >> a >> b;
    int res = dfs(a, b, 0);
    if(res == 1000000001)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}