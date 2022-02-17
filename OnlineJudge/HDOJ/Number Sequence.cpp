#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,n;
    int fab[55] = { 0, 1, 1};
    while(cin>>a>>b>>n, a||b||n)   
    {
        for(int i = 3; i<55; i++)
        {
            fab[i] = (a * fab[i - 1] + b * fab[i - 2]) % 7;
        }
        cout<<fab [ n % 48 ]<<endl;
    }
}