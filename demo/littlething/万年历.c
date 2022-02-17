#include<stdio.h>

int input()
{
	int y;
	printf("请输入年份\n");
	scanf("%d",&y);	
	return y;
 } 
 
 int *pd(int y)
 {
 	y--;
 	int d=(1+2*13+3*(13+1)/5+y+y/4-y/100+y/400)%7;
	d++;
	y++;
	int a[2];
	a[0]=y;
	a[1]=d;
	int *p=a;
	return p;
 }
void output(int*a)
{
	int y=*a;
	int d=*(a+1);
	int flag;
	int i,j,k;
	printf("这是%d年\n",y);
	for(i=1;i<13;i++)
	{	
	printf("----------------------\n");
	printf("这是%d月\n",i);
	printf(" 一 二 三 四 五 六 七\n");
	
	if(d==0&&i>1)
	{
		d=7;
	}
		for(j=1;j<d;j++)
		{
			printf("   ");
		}
		switch(i)
		{
			case 1:case 3:case 5:case 7:case 8:case 10:case 12: k=31;break;
			case 4:case 6:;case 9:case 11:k=30;break;
			case 2: if((y%4==0&&y%100!=0)||y%400==0) k=29;else k=28; break;
		}
		flag=d;
		for(j=0;j<k;j++,d++)
		{
			printf("%3d",j+1);
			if(d%7==0) printf("\n");
		}
		d=(j+flag)%7;
		printf("\n");	
	}
}
int main()
{
	output(pd(input()));
	getchar(); 
	getchar();
	return 0;
}

