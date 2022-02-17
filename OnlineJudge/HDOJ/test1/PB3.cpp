#include<iostream>
using namespace std;
int isUgly(int number){  
    while(number % 2 == 0)  
        number /= 2;  
    while(number % 3 == 0)  
        number /= 3;  
    while(number % 5 == 0)  
        number /= 5;  
     while(number % 7 == 0)  
        number /= 7;  
    return number == 1;//经典一部，可以不用判断if
}  
int main()
{
    int n,a,t=0;
    cin >> n;
    while(n--)
    {
        cin >>a;
        t = isUgly(a);
        if (t==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}