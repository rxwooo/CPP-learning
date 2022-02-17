#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while( t -- )
    {
        int n;
        long long sum = 0;
        long long big = 0;
        cin >> n;
        for ( int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            sum += num;
            if( num > big )
                big = num;
        }
        if( big * 2 <= sum + 1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}