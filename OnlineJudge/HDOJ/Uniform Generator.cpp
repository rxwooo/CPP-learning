#include<cstdio>

long long measure(long long x, long long y)
{	
	long long z = y;
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;	
	}
	return z;
}

int main()
{
    int n,c;
    long long num,pow;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        pow=1;
        scanf("%d",&c);
        for(j=0;j<c;j++)
        {
            scanf("%d",&num);
            if(j==0)
            { 
                pow=num;
                continue;
            }
            pow=pow*num/measure(pow,num);
        }
        printf("%d\n",pow);
    }
    return 0;
}