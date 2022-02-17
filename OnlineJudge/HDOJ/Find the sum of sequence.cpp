#include<stdio.h>
#include<math.h>
int main(){
	int m,n;
	int i;
	float result=0.0,x;
	while(scanf("%d %d",&n,&m)!=EOF)
    {
		x=n;
		for(i=1;i<=m;i++){
			result+=x;
			x=sqrt(x);
		}
		printf("%.2f\n",result);
	}
    return 0;
}