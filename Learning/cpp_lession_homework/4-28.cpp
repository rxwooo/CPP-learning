#include<iostream>
using namespace std;
int main ()
{
    char check;
    cout<<"Menu: A(dd) D(elete) S(elect) Q(uit). Select one:"<<endl;
    while(cin>>check)
    {
        if(check=='Q') break;
        else{
            switch(check)
            {
                case 'A':cout<<"数据已增加"<<endl; break;
                case 'D':cout<<"数据已删除"<<endl; break;
                case 'S':cout<<"数据已排序"<<endl; break;
                default: cout<<"输入错误"<<endl;
            }
        }
    }
    return 0;
}
