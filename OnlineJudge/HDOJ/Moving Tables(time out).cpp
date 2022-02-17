#include<iostream>
#include<algorithm>
using namespace std;

struct table{
    int bg,ed;
};

bool cmp1(table& a,table& b)
{
    return a.bg<b.bg;
}

int main()
{
    int c;
    cin>>c;
    for(int i=0;i<c;i++)
    {
        struct table tb[201];
        int mk=0,mj=0,count=0;
        int n;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            int ks,js;
            cin>>ks>>js;
            if(ks>mk) mk=ks;
            if(js>mj) mj=js;
            tb[j].bg=(ks+1)/2;
            tb[j].ed=(js+1)/2;
        }
        int nn=n;
        sort(tb,tb+n,cmp1);
        while(nn)
        {
            int beg=0,end=0;
            for(int j=0;j<n;j++)
            {
                if(tb[j].bg>=end&&tb[j].bg<101)
                {
                    beg=tb[j].bg;
                    end=tb[j].ed;
                    tb[j].bg=101;
                    tb[j].ed=101;
                    nn--;
                }
            }
            count++; 
        }
        cout<<count*10<<endl;
    }
}