#include <iostream>
using namespace std;

class Tree
{
public:
    Tree(int a = 0) : ages(a) {}
    Tree(const Tree &a) : ages(a.gage()) {}
    void grow(int years) { ages += years; }
    int gage() const { return ages; }
    void age() const { cout << ages << endl; }

private:
    int ages;
};

int main()
{
    Tree t1(10);
    t1.grow(5);
    Tree t2(t1);
    t2.age();
    return 0;
}