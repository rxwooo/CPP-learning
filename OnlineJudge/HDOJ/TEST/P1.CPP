#include<bits/stdc++.h>
using namespace std;

char s[4]="FHS";

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char ss[20];
        cin>>ss;
        int n;
        cin>>n;
        int flag;
        int max=0,min=0x3f3f3f3f;
        for(int i=0;i<3;i++)
        {
            if(ss[0]==s[i])
            {
                flag=i;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            int num;
            if(flag==0)
            {
                cin>>num;
                if(num<min) min=num;
            }
            else
            {
                cin>>num;
                if(num>max) max=num;
            }
        }
        cout<<(flag==0?min:max)<<endl;
    }
}