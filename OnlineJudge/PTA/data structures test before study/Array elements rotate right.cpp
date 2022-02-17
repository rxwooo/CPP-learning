#include<bits/stdc++.h>
using namespace std;

int arr[110];

int main()
{
    int num,ps;
    while(cin>>num>>ps){
        ps=ps%num;
        for(int i=ps;i<num;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<ps;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<num-1;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<arr[num-1]<<endl;
    }
    return 0;
}