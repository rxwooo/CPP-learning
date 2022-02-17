#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    while(cin>>t, t)
    {
        int ans = 0;
        for(int i = 0; i<t; i++)
        {
            int tp;
            cin>>tp;
            ans ^= tp;
        }
        if(ans)
            cout<<"Rabbit Win!"<<endl;
        else
            cout<<"Grass Win!"<<endl;
    }
    return 0;
}