#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct homework{
    int dl=0;
    int mk=0;
    bool operator <(homework& a)
    {
        if(mk==a.mk) return dl<a.dl;
        return mk>a.mk; 
    }
};

int main()
{
    int c;
    cin>>c;
    for(int i=0;i<c;i++)
    {
        struct homework hk[1001];
        int n,md=0,rc=0,sum=0;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>hk[j].dl;
            if(hk[j].dl>md) md=hk[j].dl;
        }
        for(int j=0;j<n;j++)
        {
            cin>>hk[j].mk;
            sum+=hk[j].mk;
        }
        sort(hk,hk+n);
        int d[1001]={0};
        for(int j=0;j<n;j++)
        {
            if(d[hk[j].dl]==0)
            {
                rc+=hk[j].mk;
                d[hk[j].dl]=1;
            }
            else{
                for(int k=hk[j].dl-1;k>0;k--)
                {
                    if(d[k]==0)
                    {
                        rc+=hk[j].mk;
                        d[k]=1;
                        break;
                    }
                }
            }
        }
        cout<<sum-rc<<endl;
    }
}