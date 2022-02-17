#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int a[200005]={0},cal[200005],m,mm;

int find(int x)
{
    int r = x;
    while (a[r] != r) //循环结束，则找到根节点
          r = a[r];
    int i=x;
    while (a[i]!=r)
    {
        int j=a[i];
        a[i]=r;
        i=j;
    }
    a[x]=r;   
    return r;
}

void merge(int x, int y)
{
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if (fx != fy) a[fx] = fy;
}

int main()
{
    int n;
    while (cin>>n)
    {
        if(n==0){
            cout<<"1"<<endl;
            break;
        }
        memset(cal,0,sizeof(cal));
        for(int i=1;i<200005;i++) a[i]=i;
        m=0,mm=0;

        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            merge(a,b);
            if(a>m) m=a;
            if(b>m) m=b;
        }

        for(int i=1;i<=m;i++)
        {
            cal[find(a[i])]++;
        }

        for(int i=1;i<=m;i++)
        {
            if(cal[i]>mm) mm=cal[i];
        }
        cout<<mm<<endl;
    }
    return 0;
}