#include "Stack.h"
using namespace std;



int main()
{
    Stack<int> s;
    InitStack(s);

    for (int i = 0; i < 10; i++)
    {
        Push(s, i);
        if(i % 2 == 1)
            Pop(s);
    }
    cout<<s<<endl;

}