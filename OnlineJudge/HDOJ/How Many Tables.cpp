#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int n,c;
int a[1001];

int find(int x){
    if(x==a[x]) return x;
    else find(a[x]);
}

void merge(int x,int y)
{
    int fx,fy;
    fx = find(x);
    fy = find(y);
    if(fx != fy) a[fy] = fx;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>c;
        for(int i=0;i<=n;i++) a[i]=i;

        for(int i=0;i<c;i++)
        {
            int t1,t2;
            cin>>t1>>t2;
            merge(t1,t2);
        }
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(i==a[i]) count++;
        }
        cout<<count<<endl;
    }
    return 0;   
}