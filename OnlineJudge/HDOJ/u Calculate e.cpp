#include<stdio.h>

int main()
{
    double result=1.0,e=1;
    int n=0,m;
    printf("n e\n- -----------\n");
    for(n=0;n<10;n++)
    {
        if(n==0)
        {
            printf("0 1\n");
            continue;
        }
        else{
            for(m=1;m<=n;m++)
            {
               result/=m;
            }
            e+=result;
        }
        if(e>2.5)
        printf("%d %.9f\n",n,e);
        else if(e<2.4)
        printf("%d %.0f\n",n,e);
        else printf("%d %.1f\n",n,e);
        result=1.0;
    }
    return 0;
}