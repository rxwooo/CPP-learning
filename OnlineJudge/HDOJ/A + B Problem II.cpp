#include<stdio.h>
#include<string.h>
int main()
{
    char a[1001]={0},b[1001]={0},re[1002],c;
    int aw,bw,w;
    int num=0,sum=0;
    int i,j;
    scanf("%d",&num);
    getchar();
    for(i=0;i<num;i++)
    {
        sum=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(re,0,sizeof(re));

        printf("Case %d:\n",i+1);
        for(j=0;c=getchar();j++)
        {
            if(!(c<='9'&&c>='0')) break;
            a[j]=c;
        }
        for(j=0;c=getchar();j++)
        {
            if(!(c<='9'&&c>='0')) break;
            b[j]=c;
        }
        aw=strlen(a);
        bw=strlen(b);
        w=(aw>bw?aw:bw);
        if(aw<w)
        {
            for(j=w;j-(w-aw)>=0;j--)
            {
                a[j]=a[j-(w-aw)];
            }
            for(;j>=0;j--)
            {
                a[j]='0';
            }
        }
        if(bw<w)
        {
            for(j=w-1;j-(w-bw)>=0;j--)
            {
                b[j]=b[j-(w-bw)];
            }
            for(;j>=0;j--)
            {
                b[j]='0';
            }
        }
        for(j=w-1;j>=0;j--)
        {
            sum+=a[j]-'0'+b[j]-'0';
            re[j]=sum%10+'0';
            sum-=sum%10;
            sum/=10;
        }
        if(sum!=0)
        {
            printf("%s + %s = %d%s\n\n",aw>bw?a:a+(w-aw),aw>bw?b+(w-bw):b,sum,re);
        }
        else
        {
            printf("%s + %s = %s\n\n",aw>bw?a:a+(w-aw),aw>bw?b+(w-bw):b,re);
        }
        
    }
    return 0;
}