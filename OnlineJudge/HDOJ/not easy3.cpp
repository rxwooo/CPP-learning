#include<iostream>

using namespace std;

int main(){
    int n;
    long long re=0;
    long long a[51]={3,6,6};
    for(int i=3;i<51;i++) a[i]=a[i-1]+a[i-2]*2;
    while(cin>>n)
    {
        cout<<a[n-1]<<endl;
    }
    return 0;
}