#include <bits/stdc++.h>
using namespace std;

//f4=max(f3,f2+n4)
int num[100010];
long long re(int ed,int n)
{
    if(ed==1) { num[1]=n; return num[1]; }
    if(ed==2) return num[2];
    else return max(num[ed-2]+n,num[ed-1]);
}

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            int nn;
            cin>>nn;
            num[i]=re(i,nn);
        }
        cout<<num[n]<<endl;
    }
    return 0;
}