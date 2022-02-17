#include<bits/stdc++.h>
using namespace std;

int main()
{
    while(1)
    {
        
        int n;
        cin>>n;
        if(n==0) break;
        int we;
        int er[8];
        memset(er,0,sizeof(er));
        for(int i=7;i>=0;i--)
        {
            int temp=n/pow(2,i);
            er[7-i]=temp;
            if(er[7-i]!=0) n-=pow(2,i);
        }
        for(int i=7;i>=0;i--)
        {
            if(er[i]==1)
            {
                cout<<pow(2,7-i)<<endl;
                break;
            }
        }
    }
    
}