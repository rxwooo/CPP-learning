#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int a[100010],p[100010],q[100010],si[100010];

int find(int x)
{
    int r = x;
    while (a[r] != r) //循环结束，则找到根节点
          r = a[r];  
    return r;
}

void merge(int x, int y)
{
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if(fx!=fy)
    if (x > y) a[x] = y;
    else a[y]=x;
    
}

int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        int n;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(q,0,sizeof(q));
        memset(p,0,sizeof(p));
        memset(si,0,sizeof(si));
        int t1,t2;
        for(int i=1;i<=n;i++) a[i]=i;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d",&t1,&t2);
            if(t1==0||t2==0) continue;
            merge(t1,t2);
        }
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            si[a[i]]=1;
            scanf("%d %d",&p[i],&q[i]);
        }
        for(int i=1;i<=n;i++)
        {
            int r=a[i];
            if(si[i]==0)
            do
            {
                if(p[i]>q[i])
                {
                    p[a[i]]+=(p[i]-q[i]);
                }
                r=a[r];
            }while(r!=find(i));
        }
        if(p[1]>q[1]) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}