#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct node{
    int w,u,v;
}cd[200010];

int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        int n,m;
        cin>>n>>m;
        while(n--)
        {
            cin>>cd[n].w>>cd[n].u;
            if(cd[n].u==1) cin>>cd[n].v;
        }
        for(int i=0;i<n;i++)
        {
            //背包
            if()
        }
    }
}