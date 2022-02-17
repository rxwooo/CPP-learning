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
    int num,pow;
    int i,j;
    while(scanf("%d %d",&num,&pow)!=EOF)
    {
        pow=pow*num/measure(pow,num);
        printf("%d\n",pow);
    }
    return 0;
}