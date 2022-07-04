#include<bits/stdc++.h>
using namespace std;

int main()
{
    string sa,sb;
    int da, db;
    cin >> sa >> da >> sb >> db;
    if(da == 0 && db == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int counta = 0;
    for(int i = 0; i < sa.size(); i++)
        counta += sa[i] - '0' == da;
    int countb = 0;
    for(int i = 0; i < sb.size(); i++)
        countb += sb[i] - '0' == db;

    string ans(max(counta, countb) + 1, '0');
    int c;
    int len = ans.size();
    int apos = 0;
    int bpos = 0;
    for(int i = len - 1; i >= 0; i --)
    {
        int a = apos++ >= counta? 0: da;
        int b = bpos++ >= countb? 0: db;
        int c = ans[i] - '0';
        ans[i] = (a + b + c) % 10 + '0';
        ans[i - 1] += (a + b + c) / 10;
    }
    if(ans[0] == '0' && ans.size() != 1)
        cout <<  ans.substr(1, ans.size() - 1) << endl;
    else
        cout << ans << endl;
    return 0;
}