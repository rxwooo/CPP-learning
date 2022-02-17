#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    long long re[50] =   {0, 1, 1, 5, 9, 29};
    long long born[50] = {0,1, 0, 4, 4, 20};
    for (int i = 5; i <= 40; i++)
    {
        
        born[i] = 4*(born[i-3]+born[i-2]+born[i-4]);
        re[i] = born[i]-born[i-5]+re[i-1];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<re[n]<<endl;
    }
    return 0;
}