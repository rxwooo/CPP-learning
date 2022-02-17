#include<stdio.h>
#include<math.h>
int getgen(int num)
{
	int gen=num;
	int i,j;
	for(i=5;i>=0;i--)
	{
		j=num/pow(10,i);
		gen+=j;
		num-=j*pow(10,i);
	}
	return gen;
}

int main()
{
	int gen[100000];
	int i,j;
	int num;
	for(i=0;i<100000;i++)
	{
		gen[i]=getgen(i+1);
	}
	for(;;)
	{
		scanf("%d",&num);
		for(j=0;j<100000;j++)
		{
			if(gen[j]==num)
			{
				printf("%d\n",j+1);
				break;
			}
		}
		if(j==100000)
		printf("0\n");
	}
	return 0;
}
