#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int e, m, h;
        cin >> e >> m >> h;
        int minN = e / 5;
        minN = min(m / 3, minN);
        minN = min(h, minN);
        cout << minN << endl;
    }
    return 0;
}