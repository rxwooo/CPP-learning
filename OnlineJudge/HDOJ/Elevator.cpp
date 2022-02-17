#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c=0,pd,time=0;
    int n=0;
    int i,j;
    while(cin>>n,n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&pd);
            if(pd>c) time+=((pd-c)*6+5);
            else time+=((c-pd)*4+5);
            c=pd;
        }
        printf("%d\n",time);
        time=0;
        c=0;
    }
    return 0;
}