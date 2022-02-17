#include <bits/stdc++.h>
using namespace std;
#define TElemType int
//��ʼ����ͷ�Ͷ�βָ�뿪ʼʱ��Ϊ0
int front = 0, rear = 0;
typedef struct BiTNode
{
    BiTNode()
    {
        lchild = rchild = NULL;
        data = 0xc0c0c0c0;
    }
    TElemType data;                  //������
    struct BiTNode *lchild, *rchild; //���Һ���ָ��
} BiTNode, *BiTree;
//��Ӻ���
void EnQueue(BiTree *a, BiTree node)
{
    a[rear++] = node;
}
//���Ӻ���
BiTNode *DeQueue(BiTNode **a)
{
    return a[front++];
}
//�������
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
        //����˳����У���ʼ��������������
        BiTree a[110];
        //��������
        EnQueue(a, tree);
        //����ͷ�Ͷ�β���ʱ����ʾ����Ϊ��
        while (front < rear)
        {
            //��ͷ������
            p = DeQueue(a);
            displayNode(p);
            //����ͷ�������Һ����������
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