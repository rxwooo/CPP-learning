#ifndef __BINARYTREE__
#define __BINARYTREE__

#include <bits/stdc++.h>
#include "Stack.h"
#include "Queue.h"
using namespace std;

typedef char ElementType;

enum TraMode
{
    pre,
    in,
    post
};

typedef struct BTnode
{
    ElementType data;
    BTnode *lchild;
    BTnode *rchild;
} BTnode, *BTree;

typedef void (*func)(BTnode&);

void BTreeInit(BTree& T)
{
    if (!T)
        T = NULL;
}

void BTreeDestore(BTree& T)
{
    BTreeInit(T);
    delete T;
}

void BTreeCreat(BTree& T)
{
    BTreeInit(T);
    T = new BTnode;
    ElementType ip;
    cin>>ip;
    if (ip!='!')
    {
        T->data = ip;

        BTnode *btn = new BTnode;
        T->lchild = btn;
        BTreeCreat(T->lchild);
        btn = new BTnode;
        T->rchild = btn;
        BTreeCreat(T->rchild);
    }
    else
        T = NULL;
}

bool BTreeEmpty(BTree T)
{
    return T;
}


BTnode *BTreeRoot(BTree T)
{
    if (T)
        return T;
    return NULL;
}

ElementType BTnodeValue(BTnode &btn)
{
    if (&btn)
        return btn.data;
}

void BTnodeAssign(BTnode &btn, ElementType e)
{
    btn.data = e;
}

void BTreeOdTra(BTree& T, TraMode tm, func fun)
{
    if (T)
    {
        if (tm == pre)
            fun(*T);

        if (T->lchild)
            BTreeOdTra(T->lchild, tm, fun);

        if (tm == in)
            fun(*T);

        if (T->rchild)
            BTreeOdTra(T->rchild, tm, fun);

        if (tm == post)
            fun(*T);
    }
}


void Visit(BTnode &bn)
{
    cout << bn.data << " ";
}

void inOrder(BTree b)
{
    Stack<BTree> S;
    BTnode *p;
    Push(S, b);
    while (!StackEmpty(S))
    {
        while (GetTop(S, p) && p)
            Push(S, p->lchild);
        Pop(S, p);
        if (!StackEmpty(S))
        {
            Pop(S, p);
            Visit(*p);
            Push(S, p->rchild);
        }
    }
}

void preOrder(BTree b)
{
    Stack<BTree> S;
    BTnode *p;
    Push(S, b);
    while (!StackEmpty(S))
    {
        Pop(S, p);
        if (p == NULL)
            continue;
        Visit(*p);
        Push(S, p->rchild);
        Push(S, p->lchild);
    }
}

void postOrder(BTree b)
{
    Stack<BTree> S;
    BTnode *p = b;
    Push(S, b);
    while (!StackEmpty(S))
    {
        while (GetTop(S, p))
        {
            if(p==NULL) { Pop(S,p); continue; }
            if(!(p->rchild||p->lchild)||StackEmpty(S)) break;
            Push(S, p->rchild);p->rchild = NULL;
            Push(S, p->lchild);p->lchild = NULL;
        }
        while(1)
        {
            GetTop(S,p);
            if(p) break;
            Pop(S,p);
        }
        if (!StackEmpty(S))
        {
            Pop(S, p);
            Visit(*p);
        }
    }
}

int BTreeLength(BTree bt)
{
    int lLen,rLen;
    if(bt)
    {
        lLen = BTreeLength(bt->lchild);
        rLen = BTreeLength(bt->rchild);
    }
    else return 0;
    return max(lLen,rLen) + 1;
}

int BTreeDepth(BTree bt)
{
    if(bt) 
        return 0;
    int rdp,ldp;
    if(bt->lchild&&bt->rchild)
        return 2;
    rdp = BTreeDepth(bt->rchild);
    ldp = BTreeDepth(bt->lchild);
    return max(1,max(rdp,ldp));
}

void LevelTra(BTree bt)
{
    Queue<BTree> qu;
    EnQueue(qu,bt);
    while(QueueLength(qu))
    {
        BTree tp;
        DeQueue(qu, tp);
        if(tp->lchild)
        EnQueue(qu, tp->lchild);
        if(tp->rchild)
        EnQueue(qu, tp->rchild);
        cout << tp->data;
    }
    cout << endl;
}

#endif