#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char s[32];
        int num[32];
        cin>>s;
        int count=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]<='9'&&s[i]>='0')
            {
                num[count]=s[i]-'0';
                count++;
            }
        }
        int sum=0;
        int b=count;
        for(int i=1;i<=b;i++)
        {
            sum+=pow(10,count-i)*num[i-1];
        }
        cout<<sum*513<<endl;
    }
}