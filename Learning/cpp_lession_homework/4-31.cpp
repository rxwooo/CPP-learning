#include<iostream>
using namespace std;
struct time {
    int year,mouth,day,hour,min,sec;
}t1;
int main()
{
    cin>>t1.year>>t1.mouth>>t1.day>>t1.hour>>t1.min>>t1.sec;
    cout<<t1.year<<"年"<<t1.mouth<<"月"<<t1.day<<"日"<<
	<<t1.hour<<"时"<<t1.min<<"分"<<t1.sec<<"秒"<<endl;
}
