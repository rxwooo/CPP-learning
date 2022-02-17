#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    while(cin>>num)
    {
        if (num>100||num<0)
        {
            cout<<"Score is error!"<<endl;
            continue;
        }
        char c;
        switch(num/10)
        {
            case 10:
            case 9: c = 'A'; break;
            case 8: c = 'B'; break;
            case 7: c = 'C'; break;
            case 6: c = 'D'; break;
            default:  c = 'E'; break;
        }
        cout<<c<<endl;
    }
}