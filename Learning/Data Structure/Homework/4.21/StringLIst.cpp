#include"LinkList.h"
using namespace std;

void StrAssign(Linklist<char>& l, char *c)
{
    l.len = strlen(c);
    LLnode<char> *tp = l.head;
    for(int i = 0;i<l.len;i++) 
    {
        tp->next = new LLnode<char>;
        tp = tp->next;
        tp->next = NULL;
        tp->data = c[i];
    }
}

void StrCopy(Linklist<char>& l1, Linklist<char>& l2)
{
    ClearLList(l1);
    l1.len = l2.len;
    LLnode<char> *tp1 = l1.head;
    LLnode<char> *tp2 = l2.head;
    for(int i = 0; i<l2.len;i++)
    {
        tp1->next = new LLnode<char>;
        tp1 = tp1->next;
        tp2 = tp2->next;
        tp1->next = NULL;
        tp1->data = tp2->data;
    }
}

int StrCompare(Linklist<char>& l1, Linklist<char>& l2)
{
    LLnode<char> *tp1 = l1.head;
    LLnode<char> *tp2 = l2.head;
    for(int i = 0; i<l2.len;i++)
    {
        tp1 = tp1->next;
        tp2 = tp2->next;
        if(tp1->data!=tp2->data)
            return (tp1->data) - (tp2->data) ;
    }
    return 0;
}

int Strlength(Linklist<char>& l1)
{
    LLnode<char> *tp = l1.head;
    int count = 0;
    while(tp->next!=NULL)
    {
        count++;
    }
    return 0; 
}

Linklist<char>& Concat(Linklist<char>& l1, Linklist<char>& l2)
{
    Linklist<char> *l3 = new Linklist<char>;
    l3->len = l1.len + l2.len;
    LLnode<char> *tp = l1.head;
    LLnode<char> *tp3 = l3->head;
    for(int i = 0; i<l2.len;i++)
    {
        tp3->next = new LLnode<char>;
        tp = tp->next;
        tp3 = tp3->next;
        tp3->next = NULL;
        tp3->data = tp->data;
    }
    tp = l2.head;
    for(int i = 0; i<l2.len;i++)
    {
        tp3->next = new LLnode<char>;
        tp = tp->next;
        tp3 = tp3->next;
        tp3->next = NULL;
        tp3->data = tp->data;
    }
}

Linklist<char>& SubString(Linklist<char>& l1, int pos, int len )
{
    Linklist<char> *l2 = new Linklist<char>;
    LLnode<char> *tp = l1.head;
    LLnode<char> *tp2 = l2->head;
    for(int i = 1;i<pos;i++)
        tp = tp->next;
    for(int i = 0;i<len;i++)
    {
        tp2->next = new LLnode<char>;
        tp2 = tp2->next;
        tp = tp->next;
        tp2->data = tp->data;
    }
    return *l2;
}

