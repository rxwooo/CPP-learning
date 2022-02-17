#include<algorithm>
#include<iostream>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main()
{
    int c;
    cin>>c;
    for(int i=0;i<c;i++)
    {
        int a[1001];int n;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        sort(a,a+n,cmp);
        int flag=0;
        for(int j=0;j<n;j++)
        {
            if(j+a[j]>n){
                flag=1;
            }
            for(int k=0;k<a[j];k++)
            {
                a[j+k+1]--;
                if(a[j+k+1]<0)
                {
                   flag=1;
                } 
            }
            if(flag==1) break;
            sort(a+j+1,a+n,cmp);
        }
        if(flag==1) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
}