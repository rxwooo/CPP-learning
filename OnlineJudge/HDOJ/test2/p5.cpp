#include <bits/stdc++.h>
using namespace std;

typedef struct BiTNode{
    int data;
    BiTNode *lchild, *rchild;
}BinTree;

void aftOrderTraverse(BinTree *T)
{   if(T==NULL)    return; 
    aftOrderTraverse(T->lchild);  
    aftOrderTraverse(T->rchild);
    printf("%d ", T->data);
}

void input(BinTree *T,BinTree t)
{
    if(T==NULL) { BinTree a; a.data=t.data; T=&a; return ;}
    else if(T->data>t.data) input(T->lchild,t);
    else if(T->data<t.data) input(T->rchild,t);
}

int main()
{
    BinTree tr;
    int n=0;
    while(cin>>n)
    {
        cin>>tr.data;
        for(int i=1;i<n;i++)
        {
            BinTree T;
            cin>>T.data;
            input(&tr,T);
        }
        aftOrderTraverse(&tr);
    }
    return 0;
}





