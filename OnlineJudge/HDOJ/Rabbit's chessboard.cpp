#include<iostream>
#include <math.h>
using namespace  std;

int main()
{
    long long a[36][36]={1};
    long long sum=0;
    for(int i=1;i<36;i++){
        for(int j=0;j<=i;j++)
        {
            if(j==i) a[j][j] = a[j][j-1];
            else if(j==0) a[i][j]=a[i-1][j];
            else a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    int n,count=0;
    while(cin>>n)
    {
        count++;
        if(n==-1) break;
        cout<<count<<" "<<n<<" "<<a[n][n]*2<<endl; 
    }
}