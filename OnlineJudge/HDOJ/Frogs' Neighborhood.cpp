#include<algorithm>
#include<iostream>
using namespace std;
struct hu{
    int no,num;
    bool operator <(const hu& a)
    {
        return num>a.num;
    }
};
int main()
{
    int c;
    cin>>c;
    for(int i=0;i<c;i++)
    {
        int n;
        struct hu h[11];
        int re[11][11]={0};
        cin>>n;
        for(int j=0;j<n;j++)
        {
            h[j].no=j;
            cin>>h[j].num;
        }
        sort(h,h+n);
        int flag=0;
        for(int j=0;j<n;j++)
        {
            if(j+h[j].num>n){
                flag=1;
            }
            for(int k=0;k<h[j].num;k++)
            {
                h[j+k+1].num--;
                if(h[j+k+1].num<0)
                {
                   flag=1;
                }
                else{
                    re[h[j].no][h[j+k+1].no]=1;
                    re[h[j+k+1].no][h[j].no]=1;
                }
            }
            if(flag==1) break;
            sort(h+j+1,h+n);
        }
        if(flag==1) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    printf("%d",re[j][k]);
                    if(k+1==n)
                    printf("\n");
                    else printf(" ");
                }
            }
        }
    }
    return 0;