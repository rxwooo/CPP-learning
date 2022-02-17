#ifndef __BINARYTREE__
#define __BINARYTREE__

#include <bits/stdc++.h>
using namespace std;

enum Definition
{
    pre,
    in,
    post,
    level
};

struct BTnode
{
    BTnode *right;
    BTnode *left;
    BTnode *father;
    BTree *tree;
    int data;
};
typedef void (*func)(BTnode &);

struct BTree
{
    BTree() : depth(0), degree(0), level(0), root(NULL) {}
    BTnode *root;
    int depth;
    int degree;
    int level;
};

void BTreeDestory(BTree &bt)
{
    OrderTraverse(bt,post,BTnDes);
}

void BTreeCreat(BTree &bt, Definition df)
{
    OrderTraverse(bt,df,BTnSet);
}

bool BTreeEmpty(BTree &bt)
{
    return bt.root;
}

BTnode &BTreeRoot(BTree &bt)
{
    return *bt.root;
}

int BTreeDepth(BTree &bt)
{
    return bt.depth;
}

int BTnodeValue(BTree &bt, BTnode &btn)
{
    return btn.data;
}

void BTreeAssign(BTnode &btn, int va)
{
    btn.data = va;
}

//返回参数结点的父节点的指针，若为参数为根结点，返回NULL
BTnode* BTnodeParent(BTnode &btn)
{
    if(btn.father)
        return NULL;
    return btn.father;
}

/*
    设置结点的值
    参数为树结点的引用
*/
void BTnSet(BTnode &btn)
{
    int val;
    cin>>val;
    btn.data = val;
}

/*
    访问并输出结点的值
    参数为树结点的引用
*/
void BTnVis(BTnode &btn)
{
    cout<<btn.data<<endl;
} 

/*
    用于在清空或销毁二叉树时删除结点
    参数为树结点的引用
*/
void BTnDes(BTnode& btn)
{
    delete &btn;
}

//有序遍历，参数分别为，开始遍历的结点，遍历方式和遍历过程中采取的行为（可选 BTnVis 和 BTnSet ）
void BTnodeTra(BTnode &btn,Definition def, func f)
{
    if (&btn)
    {
        if(def == pre) f(btn);
        if (btn.left)
            BTnodeTra(*btn.left, def,f);
        if(def == in) f(btn);
        if (btn.data)
            BTnodeTra(*btn.right, def,f);
        if(def == post) f(btn);
    }
}

//有序遍历，参数分别为，二叉树引用，遍历方式和遍历过程中采取的行为（可选 BTnVis 和 BTnSet ）
void OrderTraverse(BTree &bt,Definition def ,func f)
{
    BTnode *btn = bt.root;
    BTnodeTra(*btn, def,f);
}

#endif