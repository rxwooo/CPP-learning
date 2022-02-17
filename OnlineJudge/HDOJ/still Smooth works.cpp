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
    int bg,ed,len,st=0;
}r[10000];

bool cmp(road a,road b) { return a.len<b.len; }

int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int a=0,b=0,num=0,sum=0,count=0;
        for(int i=1;i<=n;i++) set[i]=i;
        for(int i=0;i<n*(n-1)/2;i++){
            scanf("%d%d%d%d",&r[i].bg,&r[i].ed,&r[i].len,&r[i].st);
            if(r[i].st)
            merge(r[i].bg,r[i].ed);
        } 
        sort(r,r+n*(n-1)/2,cmp);
        for(int i=1;i<=n*(n-1)/2;i++)  if(merge(r[i].bg,r[i].ed)) sum+=r[i].len;
        printf("%d\n",sum);
    }
    return 0;
}