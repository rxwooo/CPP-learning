#include<bits/stdc++.h>
using namespace std;

int main()
{
    srand((unsigned)time(NULL));//重新以设置时间为种子
    int a=rand();//生成一个随机数
    int b=rand()%10;//生成一个0-9的随机数
    int c=rand()%10+5;//生成一个5-14的随机数

    cout<<a<<" "<<b<<" "<<c<<endl;
    
}