#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    int num[10];
    int i,j,t;
    int n;
    for(i=0;i<10;i++)
    {
        num[i]=0;
    }
    printf("please input the end of numbers: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        char c[6];
        itoa(i,c,10);
        t=i;
        for(j=0;j<strlen(c);j++)
        {
            num[c[j]-'0']++;
        } 
    }
    for(i=0;i<10;i++)
    {
        printf("%d\n",num[i]);
    }
    return 0;
}