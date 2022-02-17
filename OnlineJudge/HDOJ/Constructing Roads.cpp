#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int set[105]={0};

int find(int x)
{
    int r = x;
    while (set[r] != r) //循环结束，则找到根节点
          r = set[r];
    int i=x;
    while (i!=r)
    {
        int j=set[i];
        set[i]=r;
        i=j;
    }   
    return r;
}


bool merge(int x, int y)
{
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if (fx != fy) set[fx] = fy;
    return fx!=fy;
}

struct road{
    int bg,ed,len;
}r[10010];

bool cmp(road a,road b) { return a.len<b.len; }

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a=0,b=0,num=0,sum=0,count=0;
        for(int i=1;i<=n;i++) set[i]=i;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(j>i) { cin>>r[num].len; r[num].bg=i; r[num++].ed=j; } else cin>>a;
        sort(r,r+num,cmp);
        int l;
        scanf("%d",&l);
        for(int i=0;i<l;i++)
        {
            scanf("%d %d",&a,&b);
            merge(a,b);
        }
        for(int i=0;i<num;i++)  if(merge(r[i].bg,r[i].ed)) sum+=r[i].len;
        printf("%d\n",sum);
    }
    return 0;
}