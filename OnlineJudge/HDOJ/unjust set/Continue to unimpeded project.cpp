#include<bits/stdc++.h>
using namespace std;

int a[1001];

int find(int x)
{
    if (x != a[x]) a[x]=find(a[x]);
    return a[x];
}

bool merge(int x, int y)
{
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if (fx > fy) a[fx] = fy;
    else a[fy] = fx;
    return fx!=fy;
}

struct road{
    int bg=0,ed=0,len=0,ck=0;
}r[5000];

bool cmp(road& a,road& b) { return a.len<b.len; }

int main()
{
    int n;
    while(cin>>n, n)
    {
        for(int i = 1; i <= n; i++) a[i] = i;
        for(int i = 1; i <= n*(n-1)/2; i++)
        {
            scanf("%d%d%d%d",&r[i].bg,&r[i].ed,&r[i].len,&r[i].ck);
            if(r[i].ck)
            merge(r[i].bg,r[i].ed);
        }
        sort(r,r+n*(n-1)/2, cmp);
        int sum = 0;
        for(int i = 1; i <= n*(n-1)/2; i++)
            if(merge(r[i].bg, r[i].ed))
                sum+=r[i].len;
        cout<<sum<<endl;
    }
    return 0;
}