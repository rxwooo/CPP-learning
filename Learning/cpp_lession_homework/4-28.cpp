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
                case 'A':cout<<"����������"<<endl; break;
                case 'D':cout<<"������ɾ��"<<endl; break;
                case 'S':cout<<"����������"<<endl; break;
                default: cout<<"�������"<<endl;
            }
        }
    }
    return 0;
}
