#ifndef __QUEUE__
#define __QUEUE__

#include "LinkList.h"
using namespace std;

template <class T>
struct Queue
{
    Queue<T>()
    {
        l = new Linklist<T>;
        InitList(*l);
    }
    Linklist<T> *l;
};

template <class T>
void InitQueue(Queue<T> &q)
{
    InitList(*q.l);
}

template <class T>
void DestroyQueue(Queue<T> &q)
{
    InitList(*q.l);
    delete q.l;
    delete &q;
}

template <class T>
void ClearQueue(Queue<T> &q)
{
    InitList(*q.l);
}

template <class T>
bool QueueEmpty(Queue<T> &q)
{
    return q.l->len;
}

template <class T>
int QueueLength(Queue<T> &q)
{
    return q.l->len;
}

template <class T>
void GetHead(Queue<T> &q, T &dt)
{
    dt = q.l->head->next->data;
}

template <class T>
void EnQueue(Queue<T> &q, T &dt)
{
    LListInsert(*(q.l), q.l->len, dt);
}

template <class T>
void DeQueue(Queue<T> &q, T n = 0)
{
    n = q.l->head->next->data;
    LListDeletByNum(*q.l, 1);
}

template <class T>
ostream &operator<<(ostream &os, Queue<T> &q)
{
    return os << (*q.l);
}

#endif