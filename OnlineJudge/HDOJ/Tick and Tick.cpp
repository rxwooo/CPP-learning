#include<stdio.h>

double abs(long double num)
{
    return num>0?num:-num;
}

double m(long double a,long double b)
{
    return a<b?a:b;
}

int check(long double a,long double b,long double c,long double num)
{
    int flag=0;
    if(a>=num) flag++;
    if(b>=num) flag++;
    if(c>=num) flag++;
    if(flag==3) return 1;
    else return 0;
}

int main()
{
    double ht=0;
    long double hour=0,min=0,sec=0;
    double D,ang=0;
    int i,j,k;
    int flag=0;
    for(;;)
    {
        scanf("%lf",&D);
        if(D==-1) break;
        ang=D/360;
        ht=0;
        hour=0;min=0;sec=0;
        for(i=0;i<12;i++)
        {
            for(j=0;j<60;j++)
            {
                for(k=1;k<=60;k++)
                {
                    hour=k*1.0/43200+j*1.0/720;
                    min=k*1.0/60+j;
                    sec=k;
                    if(hour>=60) hour-=60;
                    if(sec>=60) sec-=60;
                    if(min>=60) min-=60;
                    // long double zhs=abs((sec-hour)/60.0),fhs=abs(1.0-zhs);
                    // long double zms=abs((sec-min)/60.0),fms=abs(1.0-zms);
                    // long double zhm=abs((min-hour)/60.0),fhm=abs(1.0-zhm);
                    // long double hs=m(zhs,fhs),ms=m(zms,fms),hm=m(zhm,fhm);
                    //if(check(hs,ms,hm,ang)) ht++;
                    
                }
            }
        }
        printf("%.3lf\n",ht/12.0/60/60*100);
    }

    return 0;
}