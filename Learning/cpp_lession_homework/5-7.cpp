#include <iostream>
using namespace std;

class Cat
{
public:
    Cat(int n) : kinds(n) {}
    static int getNumOfCats() { return numOfCats; }

private:
    int kinds;
    static int numOfCats;
};

int Cat::numOfCats=8;

int main()
{
    Cat c(6);
    cout<<c.getNumOfCats()<<endl;
    return 0;
}