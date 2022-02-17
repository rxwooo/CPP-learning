#include<stdio.h>
int main()
{
    long i=2,j;
    int f[10]={1,2};
    for(;i<10;i++)
    {
        f[i]=(f[i-1]+f[i-2])%3;
    }
    while(scanf("%d",&j)!=EOF)
    {
        if(f[j%8]==0) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}          