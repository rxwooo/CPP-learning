#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string s;
    int count=0;
    while(m--)
    {
        char c[102];
        cin>>c;
        if(s.length()+strlen(c)>=n) break;
        if (s.find(c)==s.npos) 
        { 
            count++;
        }
        s.append(c);
        s+=" ";
    }
    cout<<count<<endl;
}