#include<algorithm>
#include<iostream>
using namespace std;
int i=1,j=1,k=1,l=1,n=5842;
int re[5843];

int main()
{
    char s[10][3]={"th","st","nd","rd","th","th","th","th","th","th"};
    re[1]=1;
    for(int z=2;z<=n;z++)
    {
        re[z]=min(re[i]*2,min(re[j]*3,min(re[k]*5,re[l]*7)));
        if(re[z]==re[i]*2) i++;
        if(re[z]==re[j]*3) j++;
        if(re[z]==re[k]*5) k++;
        if(re[z]==re[l]*7) l++;
    }
    int c;
    while (cin>>c)
    {
        if(c==0) break;
        cout<<"The "<<c<<s[c%10]<<" humble number is "<<re[c]<<"."<<endl;
    }
    return 0;
}