#include <bits/stdc++.h>
using namespace std;
#define TElemType int
//初始化队头和队尾指针开始时都为0
int front = 0, rear = 0;
typedef struct BiTNode
{
    BiTNode()
    {
        lchild = rchild = NULL;
        data = 0xc0c0c0c0;
    }
    TElemType data;                  //数据域
    struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;
//入队函数
void EnQueue(BiTree *a, BiTree node)
{
    a[rear++] = node;
}
//出队函数
BiTNode *DeQueue(BiTNode **a)
{
    return a[front++];
}
//输出函数
void displayNode(BiTree node)
{
    printf("%d ", node->data);
}


void insert(int n, BiTree tree)
{
    if (n < tree->data)
    {
        if (tree->lchild == NULL)
        {
            BiTree tp = new BiTNode;
            tree->lchild = tp;
        }
        insert(n, tree->lchild);
    }
    else
    {
        if (tree->rchild == NULL)
        {
            BiTree tp = new BiTNode;
            tree->rchild = tp;
        }
        insert(n, tree->rchild);
    }
}

int main()
{
    int num;
    while (cin >> num)
    {
        front = rear = 0;
        BiTree tree = new BiTNode;
        int dt;
        cin>>dt;
        tree->data = dt;
        for (int i = 1; i < num; i++)
        {
            cin >> dt;
            insert(dt, tree);
        }
        BiTNode *p;
        //采用顺序队列，初始化创建队列数组
        BiTree a[110];
        //根结点入队
        EnQueue(a, tree);
        //当队头和队尾相等时，表示队列为空
        while (front < rear)
        {
            //队头结点出队
            p = DeQueue(a);
            displayNode(p);
            //将队头结点的左右孩子依次入队
            if (p->lchild != NULL)
            {
                EnQueue(a, p->lchild);
            }
            if (p->rchild != NULL)
            {
                EnQueue(a, p->rchild);
            }
        }
    }
    return 0;
}