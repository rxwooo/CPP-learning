#include<bits/stdc++.h>
using namespace std;

int num[1010];

int main()
{
    int n;
    while(cin>>n)
    {
        memset(num, 0, sizeof(num));
        num[0] = 0;
        for(int i = 0;i<=n;i++)
        {
            if(num[i] == 0)
            for(int j = 0; ;j++)
            {
                int p = pow(2,j);
                if(p+i>n)
                    break;
                num[p+i] = 1;
            }
        }
        int flag = 1;
        for(int i = 0;;i++)
        {
            int p = pow(2,i);
            if(n - p < 0)
                break;
            if(num[n - p]==0)
            {
                flag = 0;
                cout<<"Kiki"<<endl;
                break;
            }
        }
        if(flag)
            cout<<"Cici"<<endl;
    }
    return 0;
}