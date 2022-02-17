#include<bits/stdc++.h>
using namespace std;

int sg[1010];
int a[1010];
int m,n;

int g(int x)
{
    int mex[10010];
    memset(mex, 0, sizeof(mex));
    if(sg[x]!= -1)
        return sg[x];
    for(int i = 1; i<n; i++)
    {
        int t = x - a[i];
        if(t<0)
            break;
        if(sg[i]==-1)
            sg[i] = g(t);
        mex[sg[i]] = 1;
    }
    for(int i = 0;;i++)
        if(!mex[i])
            return i;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        sg[m] = g(n);
        int count = 0;
        for(int i = 1; i<=n ; i++)
            if(sg[m-i] == 0&&m - i>0)
                count++;
        if(count)
            cout<<"Grass"<<endl;
        else
            cout<<"Rabbit"<<endl;
    }
    return 0;
}