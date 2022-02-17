#include<stdio.h>
int main ()
{
    int a,b,sum,i;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a==0&&b==0) break;
        sum=a;
        for(i=2;i<=b;i++)
        {
            sum*=a;
            sum=sum%1000;
        }
       printf("%d\n",sum);
    }
    return 0;
}

int power(int a, int b)
{
    int ans;
    if(b==0) return 1;
    else
    {
        ans=power(a*a,b/2);
        if(b%2==1) ans*=a;
    }
    return ans;
}