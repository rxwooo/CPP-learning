#include<bits/stdc++.h>
using namespace std;

int main()
{
    int dp[10];
    int flag;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 10; i++)
        cin >> dp[i];
    for(int i = 1; i < 10; i++)
        if(dp[i] != 0) 
        {
            flag = i;
            dp[i] --;
            break;
        }
    cout << flag;
    for(int i = 0; i < 10; i++)
        while(dp[i]--)
            cout << i;
    cout << endl;
    return 0;
}