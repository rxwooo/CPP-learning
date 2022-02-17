#include<bits/stdc++.h>
using namespace std;

int num[1010];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(num, 0 ,sizeof(num));
        int m,n;
        cin>>n>>m;
        num[0]=0;
        for(int i = 0; i<=n; i++)
        {
            if(num[i]==0)
            for(int j = 1; j<=m ; j++)
            {
                if(i+j>n) break;
                num[i+j] = 1;
            }
        }
        int count = 0;
        for(int i = 1; i<=m; i++)
        {
            if(num[n-i]==1)
            {
                count++;
            }
        }
        if(count == m)
            cout<<"second"<<endl;
        else 
            cout<<"first"<<endl;
    }
}