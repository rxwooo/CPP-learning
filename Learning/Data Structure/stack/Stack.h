#ifndef __STACK__
#define __STACK__

#include "LinkList.h"
using namespace std;

template <class T>
struct Stack
{
    Stack()
    {
        l = new Linklist<T>;
        InitList(*l);
    }
    Linklist<T> *l;
};

template <class T>
void InitStack(Stack<T> &s)
{
    InitList(*s.l);
}

template <class T>
void DestroyStack(Stack<T> &s)
{
    InitList(*s.l);
    delete s.l;
    delete &s;
}

template <class T>
void ClearStack(Stack<T> &s)
{
    InitList(*s.l);
}

template <class T>
bool StackEmpty(Stack<T> &s)
{
    return s.l->len;
}

template <class T>
int StackLength(Stack<T> &s)
{
    return s.l->len;
}

template <class T>
void GetTop(Stack<T> &s, T &dt)
{
    dt = s.l->head->next->data;
}

template <class T>
void Push(Stack<T> &s, T &dt)
{
    LListInsert(*s.l, 0, dt);
}

template <class T>
void Pop(Stack<T> &s, T dt = 0)
{
    dt = s.l->tail->data;
    LListDeletByNum(*s.l, s.l->len);
}

template <class T>
ostream& operator << (ostream& os , Stack<T> s)
{
    return os<< *s.l<<endl;
}

#endif