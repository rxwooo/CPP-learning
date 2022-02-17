#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,m,x,y;
        scanf("%d %d %d %d",&n,&m,&x,&y);
        int count=1;
        int rd=1;
        int now=n-x;
        if(x>y)
        {
            count+=now/(x-y);
            rd=count;
            now=now%(x-y);
            while(1)
            {
                if((x-now)%y!=0) rd++;
                rd+=(x-now)/y;

                if(rd>m) break;
                count++;
                now=(x-now)%y;
            }
        }
        else
        {
            count=m;
        }
        printf("%d\n",count);
    }
}