#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,e;
        double pe,se,be;
        cin>>a>>b>>c>>d>>e;
        pe = a*a;
        se = b*c;
        be = d*e*0.5;
        double re = max(pe,se);
        re = max(re,be);

        if(re == pe)
        {
            cout<<"Perch"<<endl;
        }
        else if(re == se)
            cout<<"Semon"<<endl;
        else 
            cout<<"Belinda"<<endl;
    }
}