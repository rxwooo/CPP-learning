#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int a[500010],dp[500010][500010];

int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int max=0;
                dp[i][j]

            }
        }
    }
}

