#include<bits/stdc++.h>
using namespace std;

int a[1001];

int find(int x)
{
    if (x == a[x]) return x;
    else find(a[x]);
}

void merge(int x, int y)
{
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if (fx > fy) a[fx] = fy;
    else a[fy] = fx;
}

int main()
{
    int n,m;
    while(cin>>n, n)
    {
        cin>>m;
        for(int i = 1 ;i<=n;i++) a[i] = i;
        for(int i = 1; i <= m; i++)
        {
            int bg,ed;
            cin>>bg>>ed;
            merge(bg, ed);
        }
        int count = 0;
        for(int i = 1; i<=n; i++)
        {
            if(a[i] == i) count++;
        }
        cout<<(count==0?0:count-1)<<endl;
    }
    return 0;
}