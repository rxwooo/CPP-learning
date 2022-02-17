#include <iostream>

using namespace std;

class student
{
private:
    long long num;
    double grade;
public:
    student(long long n=0,double gd=0):num(n),grade(gd) {};

    void wng (long long n,double gd) {num=n; grade=gd;}
    void show () const
    {
        printf("%d %.1lf\n",num,grade); 
    }
 };

 int main()
 {
     int n;
     double gd;
     student p[5];
     for(int i=0;i<5;i++)
     {
        cin>>n>>gd;
        p[i].wng(n,gd);
     }
     for(int i=0;i<5;i+=2)
     {
        p[i].show();
     }
     return 0;
 }
