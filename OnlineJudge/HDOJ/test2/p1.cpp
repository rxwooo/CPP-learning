#include<bits/stdc++.h>
using namespace std;

int num[60];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double sum=0;
        int count=0;
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
        {
            cin>>num[i];
            sum+=num[i];
        }
        sort(num,num+n);
        sum=sum*1.0/n;
        for(int i=0;i<n;i++)
        {
            if(sum<=num[i])
            {
                count=i;
                break;
            }
        }
        printf("%.2f %d\n",sum,n-count);
    }
}