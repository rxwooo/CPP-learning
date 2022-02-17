#ifndef __STACK__
#define __STACK__

#include "LinkList.h"
using namespace std;

template <typename T>
struct Stack
{
    Stack()
    {
        l = new Linklist<T>;
        InitList(*l);
    }
    Linklist<T> *l;
};

template <typename T>
void InitStack(Stack<T> &s)
{
    InitList(*s.l);
}

template <typename T>
void DestroyStack(Stack<T> &s)
{
    InitList(*s.l);
    delete s.l;
    delete &s;
}

template <typename T>
void ClearStack(Stack<T> &s)
{
    InitList(*s.l);
}

template <typename T>
bool StackEmpty(Stack<T> &s)
{
    return s.l->len;
}

template <typename T>
int StackLength(Stack<T> &s)
{
    return s.l->len;
}

template <typename T>
void GetTop(Stack<T> &s, T &dt)
{
    dt = s.l->head->next->data;
}

template <typename T>
void Push(Stack<T> &s, T &dt)
{
    LListInsert<T>(*(s.l), 0, dt);
}

template <typename T>
LLnode<T> Pop(Stack<T> &s, T dt = *(new T))
{
    int pos;
    LLnode<T> re;
    dt = s.l->tail->data;
    pos = s.l->tail->pos;
    re = LListDeletByNum(*s.l, s.l->len);
    re.pos = pos;
    return re;
}

template <typename T>
ostream& operator << (ostream& os , Stack<T> s)
{
    return os<< *s.l<<endl;
}

#endif