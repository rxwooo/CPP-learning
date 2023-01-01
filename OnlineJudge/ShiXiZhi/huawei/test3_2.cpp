#include<bits/stdc++.h>
using namespace std;

int main()
{
    int target;
    int n;
    cin >> target;
    cin >> n;
    vector<int> dist(n + 2);
    vector<int> wait(n + 2);
    vector<int> dp(n + 2, 0x3f3f3f3f); 
    for(int i = 1; i <= n; i++)
    {
        cin >> dist[i];
        cin >> wait[i];
    }
    if(target <= 1000)
        return target / 100;

    dist[0] = 0;
    dist[n + 1] = target;
    wait[0] = -1;
    wait[n + 1] = -1;
    dp[0] = 0;

    for(int i = 1; i <= n + 1; i ++)
    {
        for(int j = i - 1; j >= 0; j --)
        {
            if(dist[i] - dist[j] > 1000)
                break;
            dp[i] = min(dp[i], dp[j] + wait[j] + 1);
        }
    }
    if(dp[n + 1] == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << dp[n] + target / 100 << endl;
    return 0;
}