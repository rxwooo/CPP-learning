#include<bits/stdc++.h>
using namespace std;

int main()
{
    int count1 = 0;
    int n;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++)
    {
        int c = getchar() - '0';
        count1 += c * (i + 1);
    }
    int minAbs = (int)abs(count1);
    for(int i = 1; i <= n; i++)
    {
        count1 -= i;
        if((int)abs(count1) < minAbs)
            minAbs = (int)abs(count1);
    }
    cout << minAbs << endl;
    return 0;
}