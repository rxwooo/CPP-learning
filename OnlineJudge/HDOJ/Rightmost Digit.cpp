#include<stdio.h>
int  fun(int a){
	int ans=1,b=a;
	a=a%10;
	while(b){
		if(b%2)
			ans=(ans*a)%10;
		a=(a*a)%10;
		b/=2;
	}
	return ans; 
}
int main(){
	int a,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&a);
		printf("%d\n",fun(a));
	}
		
	return 0;
}