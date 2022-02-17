#include <bits/stdc++.h>
using namespace std;

//存储每一个仓库的需求和存量，算出性价比
struct node{
    int jb,rq;
    double ratio;
};

bool cmp(node &n1, node &n2)
{
    if(abs(n1.ratio-n2.ratio)<0.0000001) return  n1.jb>n2.jb; 
        return n1.ratio>n2.ratio;
}

int main()
{
    int m,n;
    node wh[1010]; 
    while(cin>>m>>n, m!=-1)
    {
        double sum=0;
        memset(wh,0,sizeof(wh));
        for(int i=0;i<n;i++)
        {
            cin>>wh[i].jb>>wh[i].rq;
            wh[i].ratio=wh[i].jb*1.0/wh[i].rq;
        }
        sort(wh,wh+n,cmp);
        for(int i=0;i<n&&m!=0;i++)
        {
            if(m>=wh[i].rq)
            {
                sum+=wh[i].jb;
                m-=wh[i].rq;
            }
            else
            {
                sum+=m*1.0/wh[i].rq*wh[i].jb;
                m=0;
            }
        }
        printf("%.3f\n",sum);
    }    
}