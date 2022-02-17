#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    while(cin>>num)
    {
        int flag = 1;
        int ans = 1;
        int n;
        while(num--)
        {
            cin>>n;
            if(n%2==1)
            {
                flag = 1;
                ans *= n;
            }
        }
        if(flag) cout<<ans<<endl;
        else cout<<"-1"<<endl;
    }
}