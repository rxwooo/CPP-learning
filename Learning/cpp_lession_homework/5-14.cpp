#include<iostream>
using namespace std;

class Boat;
class Car{

public:
    Car(double n) : weight(n) {}
    Car(const Car& a) : weight(a.getwe()) {}
    double getwe () const { return weight; }

private:
    double weight;
    friend double gettotalWeight(Car& c,Boat& b); 
};

class Boat{

public:
    Boat(double n) : weight(n) {}
    Boat(const Boat& a) : weight(a.getwe()) {}
    double getwe () const { return weight; }

private:
    double weight;
    friend double  gettotalWeight(Car& c,Boat& b);
};

double  gettotalWeight(Car& c,Boat& b) {return c.getwe()+b.getwe();}

int main()
{
    Boat b(5.5);
    Car c(7.5);
    cout<<gettotalWeight(c,b)<<endl;
    return 0;
}