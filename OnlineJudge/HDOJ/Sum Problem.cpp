#include<stdio.h>

int main()
{
    int num;
    int sum=0;
    int i;
    while(scanf("%d",&num)!=EOF)
    {
        for(i=0;i<num;i++)
        {
            sum+=i+1;
        }
        printf("%d\n\n",sum);
        sum=0;
    }
}
