#include<iostream>

using namespace std;

long long a[10001]={2};

int main()
{
    for(int i=1;i<10001;i++)
    {
        a[i]=a[i-1]+((i+1)*2-1)*2-1;
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        cout<<a[b-1]<<endl;
    }
    return 0;
    
}