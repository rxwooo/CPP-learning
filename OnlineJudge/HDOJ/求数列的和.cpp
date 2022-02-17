#include<bits/stdc++.h>
using namespace std;

double sq(double num, int pos)
{
    if(pos==1)  return num; 
    return num+sq(sqrt(num),pos-1);
}

int main()
{
    double num;
    while(cin>>num)
    {
        int ceng;
        cin>>ceng;
        printf("%.2f\n",sq(num,ceng));
    }
    
}