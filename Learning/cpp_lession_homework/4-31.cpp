#include<iostream>
using namespace std;
struct time {
    int year,mouth,day,hour,min,sec;
}t1;
int main()
{
    cin>>t1.year>>t1.mouth>>t1.day>>t1.hour>>t1.min>>t1.sec;
    cout<<t1.year<<"��"<<t1.mouth<<"��"<<t1.day<<"��"<<
	<<t1.hour<<"ʱ"<<t1.min<<"��"<<t1.sec<<"��"<<endl;
}
