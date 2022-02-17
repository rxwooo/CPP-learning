#include"Queue.h"
using namespace std;

int main()
{
    Queue<int> q;
    InitQueue(q);

    for(int i = 0; i<10; i++)
    {
        EnQueue(q, i);
    }
    for(int i = 0; i<5; i++)
    {
        DeQueue(q);
    }
    cout<<q<<endl;
}