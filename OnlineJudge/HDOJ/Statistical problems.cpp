#include<iostream>
using namespace std;

int main(){
    long long a[31]={3,7};
    for(int i=2;i<31;i++)
    {
        a[i]=2*a[i-1]+a[i-2];
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        cout<<a[num-1]<<endl;
    }
    return 0;
}