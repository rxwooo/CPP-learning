#include "Stack.h"
#include <bits/stdc++.h>
using namespace std;

typedef struct BTree
{
    int data;
    BTree *lchild;
    BTree *rchild;
} Bnode, *Btree;

Btree CreatTestBtree()
{
    Btree L = new BTree;
    BTree *tp = new BTree, *p = L;
    L->lchild = tp;
    tp = new Bnode;
    L->rchild = tp;
    L->data = 1;
    L->lchild->data = 2;
    L->rchild->data = 5;
    L = L->lchild;
    tp = new Bnode;
    L->lchild = tp;
    tp = new Bnode;
    L->rchild = tp;
    L->lchild->data = 3;
    L->rchild->data = 4;
    L->lchild->lchild = L->lchild->rchild = L->rchild->lchild = L->rchild->rchild = NULL;
    L = p;
    L = L->rchild;
    tp = new Bnode;
    L->rchild = tp;
    L->rchild->data = 6;
    L->lchild = NULL;
    L = L->rchild;
    tp = new Bnode;
    L->lchild = tp;
    L->lchild->data = 7;
    L->rchild = NULL;
    L->lchild->lchild = L->lchild->rchild = NULL;
    return p;
}

void Visit(Bnode *bn)
{
    cout << bn->data << " ";
}

void inOrder(Btree b)
{
    Stack<Btree> S;
    Bnode *p;
    Push(S, b);
    while (!StackEmpty(S))
    {
        while (GetTop(S, p) && p)
            Push(S, p->lchild);
        Pop(S, p);
        if (!StackEmpty(S))
        {
            Pop(S, p);
            Visit(p);
            Push(S, p->rchild);
        }
    }
}

void preOrder(Btree b)
{
    Stack<Btree> S;
    Bnode *p;
    Push(S, b);
    while (!StackEmpty(S))
    {
        Pop(S, p);
        if (p == NULL)
            continue;
        Visit(p);
        Push(S, p->rchild);
        Push(S, p->lchild);
    }
}

void postOrder(Btree b)
{
    Stack<Btree> S;
    Stack<Btree> T;
    Bnode *p = b;
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
            Visit(p);
        }
    }
}

int CreatBTree()
{
    
}



/*
测试的树为：
         1
        - -    
      -    -
    2        5
   - -        -
 -    -         -
3       4         6
                 -  
               -
             7
*/

int main()
{
    cout<<"postOrder: ";
    preOrder(CreatTestBtree());
    cout<<endl;
    cout<<endl;
    cout<<"inOrder:   ";
    inOrder(CreatTestBtree());
    cout<<endl;
    cout<<endl;
    cout<<"postOrder: ";
    postOrder(CreatTestBtree());
    cout<<endl;
    return 0;
}


