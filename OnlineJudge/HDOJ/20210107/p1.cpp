#include<iostream>
using namespace std;

int main()
{
    long long n=0;
	long long i=1,j=1,k=1,l=1;
    
    while(cin >> n)
    {
		if(n==0) break;
		i=j=k=l=1;
        while(n % 2 == 0)
	{
        n /= 2;
		i++;
	}    
    while(n % 3 == 0)
	{
        n /= 3;
		j++;
	}   
    while(n % 5 == 0)
	{
        n /= 5;
		k++;
	}    
     while(n % 7 == 0)
	 {
        n /= 7;
		l++;
	 }
    cout<<i*j*k*l<<endl;
    }
    return 0;
}