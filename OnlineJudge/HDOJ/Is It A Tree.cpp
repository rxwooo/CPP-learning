#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int n,c,flag;
int a[100010],sign[100010]={0},ff[100010]={0};
char p[2][20]={" is a tree."," is not a tree."};

int find(int x){
    if(x==a[x]) return x;
    else find(a[x]);
}

bool merge(int x, int y)
{
    int fx, fy;
    fx = find(x);
    fy = find(y);
    if (fx != fy) a[y] = fx;
    return fx==fy;
}

int main()
{
    int m,n,count=1,max;
    while(cin>>n>>m)
    {
        max=0;
        memset(a,0,sizeof(a));
        memset(sign,0,sizeof(sign));
        memset(ff,0,sizeof(ff));
        for(int i=1;i<=100010;i++) a[i]=i;
        flag=0;
        if(n<0&&m<0) break;
         
        do
        {
            if(m>max) max=m;
            if(n>max) max=n;
            if( n==0&&m==0 ) break;
            ff[m]=1;ff[n]=1;
            if( sign[m]==1 ){
                flag=1;
                while(cin>>n>>m) if( n==0&&m==0 ) break;
                break;
            }    
            if(merge(n,m))
            {
                while(cin>>n>>m) if( n==0&&m==0 ) break;
                flag=1;
                break;
            }
            sign[m]=1;
        }while(cin>>n>>m);
        int cc=0;
        for(int i=1;i<=max;i++) if(ff[i]==0) continue; else if(a[i]==i) cc++;
        if(cc>1) flag=1;
        cout<<"Case "<<count<<p[flag]<<endl;
        count++;
    }
}
