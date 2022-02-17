#include <bits/stdc++.h>
using namespace std;

using ElementType = char;

typedef struct QuNode
{
    ElementType data;
    QuNode *next;
    QuNode *pre;
} * Queue;

void QuInit(Queue qu)
{
    QuNode *qn = qu->next;
    if (!qu)
        qu->next = new QuNode;
    else
    {
        QuNode *tp = qn;
        while (tp)
        {
            tp = qn->next;
            delete tp;
        }
    }
}

void QuPop(Queue qu)
{
    if (qu->next)
    {
        QuNode *tp = qu->next;
        tp->next->pre = qu;
        qu->next = tp->next;
        delete tp;
    }
    else
    {
        return;
    }
}

void QuPush(Queue qu, ElementType data)
{
    QuNode *tp = qu;
    if (qu->next)
    {
        while (tp->next)
            tp = tp->next;
        QuNode *ttp = new QuNode;
        ttp->data = data;
        tp->next = ttp;
        ttp->pre = tp;
        ttp->next = NULL;
    }
    else
    {
        tp = new QuNode;
        tp->data = data;
        qu->next = tp;
        tp->pre = qu;
        tp->next = NULL;
    }
}



int main()
{
}