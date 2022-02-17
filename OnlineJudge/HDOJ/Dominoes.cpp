#include<iostream>

using namespace std;

int main()
{
    long long a[51]={1,2};
    for(int i=2;i<51;i++) a[i]=a[i-2]+a[i-1];
    int n;
    while(cin>>n){
        cout<<a[n-1]<<endl;
    }
    return 0;
}