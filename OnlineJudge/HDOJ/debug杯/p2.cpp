#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct st{
    int x,y;
}s[1010],ce1,ce2;

int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        ce1.x=(n+1)/2;ce1.y=m/2;
        ce2.x=(n+1)/2;ce2.y=m/2+1;
        while(k--)
        {
            cin>>s[k].x>>s[k].y;
        }
        //背包
    }
}