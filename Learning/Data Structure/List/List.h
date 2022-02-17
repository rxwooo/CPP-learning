#ifndef __LIST__
#define __LIST__

#include<bits/stdc++.h>
using namespace std;
using ElementType = int;
const int MAXLEN = 10000;

typedef struct List {
    List() {ele = new ElementType[MAXLEN + 1]; length = 0; listsize = MAXLEN;}
    ElementType *ele;   
    int length;
    int listsize;
}List;

void DestoryList ( List& l )
{
    delete[] l.ele;
    l.length = 0;
    l.listsize = 0;
}

void ClearList( List& l )
{
    delete[] l.ele; l.ele = new ElementType[MAXLEN+1];l.length = 0; l.listsize = MAXLEN;
}

int ListEmpty( List& l )
{
    return l.length;
}

ElementType GetElem( List& l, int n )
{
    return l.ele[n];
}

int LocateElem( List& l, ElementType e, bool (*func)(ElementType a, ElementType b))
{
    for(int i = 1; i <= l.length; i++)
        if(func(e,l.ele[i]) == 1)
            return i;
    return 0;
}

ElementType PriorElem( List& l, ElementType cur)
{
    if(l.ele[1] == cur)
        return -1;
    else
        for(int i = 2; i <= l.length; i++)
            if(l.ele[i] == cur)
                return l.ele[i - 1];
    return -1;
}

ElementType NextElem( List& l, ElementType cur)
{
    if(l.ele[l.length] == cur)
        return -1;
    else
        for(int i = 1; i <= l.length - 1; i++)
            if(l.ele[i] == cur)
                return l.ele[i + 1];
    return -1;
}

void ListInsert( List& l, int pos, ElementType dt)
{
    if(l.length + 1 > l.listsize)
        return;
    l.length++;
    int p = l.length;
    while(p!=pos)
    {
        l.ele[p] = l.ele[p - 1];
        p--;
    }
   l.ele[pos] = dt;
}

void ListDelete( List& l, int pos)
{
    if( pos<1||pos>l.length)
        return; 
    for( int i = pos; i<l.length; i++) 
        l.ele[i] = l.ele[i+1];
    l.length --;
}

void ListEleVis( ElementType e )
{
    cout << e << endl;
}

void ListTraverse( List & l )
{
    if(l.length > 0)
        for(int i = 1; i <= l.length; i++)
            ListEleVis(l.ele[i]);
    return ;
}

#endif