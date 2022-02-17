#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int a[1001];
int sum;

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
    int bg=0,ed=0,len=0;
}re[5000];

bool cmp(road& a,road& b) { return a.len<b.len; }

int main()
{
    int n;
    while(cin>>n,n)
    {
        sum=0;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++) a[i]=i;
        for(int i=1;i<=n*(n-1)/2;i++) cin>>re[i].bg>>re[i].ed>>re[i].len;
        sort(re+1,re+n*(n-1)/2+1,cmp);

        for(int i=1;i<=n*(n-1)/2;i++)  if(merge(re[i].bg,re[i].ed)) sum+=re[i].len;
        cout<<sum<<endl;
    }
    return 0;
}