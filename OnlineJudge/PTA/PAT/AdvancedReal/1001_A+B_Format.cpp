#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int re = a + b;
    string ans = "";
    int count = 0;
    int flag = re < 0;
    if(flag)
        re = -re;
    if(re == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    while(re > 0)
    {
        if(count%3 == 0 && count)
            ans = "," + ans;
        ans = (char)(re % 10 + '0') + ans;
        re /= 10;
        count ++;
    }
    if(flag)
        ans = "-" + ans;
    cout << ans << endl;
    return 0;
}