#include<bits/stdc++.h>
using namespace std;

int mp[1010];
int n,m;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        bool check=n%(m+1);
        if(check) cout<<"first"<<endl;
        else cout<<"second"<<endl;
    }
    return 0;
}