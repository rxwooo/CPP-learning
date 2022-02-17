#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;

double EPS = 1e-6;
double sum=0;

int set[210]={0};

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

struct island{
    int x,y;
}is[210];

struct road{
    int bg,ed;
    double len;
}r[10010];

bool cmp(road a,road b) { return a.len <b.len; }

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int c;
        cin>>c;
        for(int i=1;i<=c;i++) cin>>is[i].x>>is[i].y;
        int a=0,b=0,num=0,count=0;
        sum=0;
        for(int i=1;i<=c;i++) set[i]=i;
        for(int i=1;i<=c;i++) 
            for(int j=1;j<=c;j++)
            {
                double d=sqrt(pow(is[i].x-is[j].x,2)+pow(is[i].y-is[j].y,2));
                if(j>i&&d>=10&&d<=1000) 
                    { r[num].len=d; r[num].bg=i; r[num++].ed=j; }
            }
        sort(r,r+num,cmp);

        for(int i=0;i<num;i++)
        {
            if(merge(r[i].bg,r[i].ed)) sum+=r[i].len;
        }
        for(int i=1;i<=c;i++)
        {
            if(set[i]==i) count++;
        }

        if(count>1) cout<<"oh!"<<endl;
        else printf("%.1f\n",sum*100);
    }
   return 0; 
}