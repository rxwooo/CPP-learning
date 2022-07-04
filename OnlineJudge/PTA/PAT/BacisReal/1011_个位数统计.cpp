#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int dp[10];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < s.size(); i++)
        dp[s[i] - '0'] ++;
    for(int i = 0; i < 10; i++)
        if(dp[i] != 0)
            cout << i << ":" << dp[i] << endl;
    return 0;
}