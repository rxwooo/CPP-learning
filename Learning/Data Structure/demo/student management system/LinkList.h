#ifndef __LINKLIST__
#define __LINKLIST__

#include <bits/stdc++.h>
using namespace std;

#define DefaultList 10

//结点结构体，存储结点数据和下一个结点的指针
template <typename T>
struct LLnode
{
    LLnode() { pos = -1; }
    T data;       //结点数据
    LLnode *next; //下一节点的指针
    LLnode *prev; //上一节点的指针
    int pos;      //结点被删除时的位序
};

//链表结构体，引导一个链表,该链表包含一个空的头结点
template <typename T>
struct Linklist
{
    Linklist() : len(0) { InitList(*this); } //保证链表初始长度为 0
    LLnode<T> *head;                         //头结点
    LLnode<T> *tail;                         //尾结点
    int len;                                 //链表长度
};

//初始化一个空链表，头结点next指针指向NULL
template <typename T>
void InitList(Linklist<T> &l)
{
    //若链表为非空，清空链表并释放内存
    if (l.len != 0)
    {
        LLnode<T> *p, *tp;
        p = l.head;
        //遍历清空并释放空间
        for (int i = 0; i <= l.len; i++)
        {
            tp = p->next;
            delete p;
            p = tp;
        }
    }

    //创建空链表
    LLnode<T> *tp = new LLnode<T>;
    l.len = 0;
    l.head = tp;
    tp->prev = l.head;
    l.tail = l.head;
    l.head->next = NULL;
}

template <typename T>
void DestroyLList(Linklist<T> &l)
{
    InitList(l);
    delete l.head;
    delete l;
}

template <typename T>
void ClearLList(Linklist<T> &l)
{
    InitList(l);
}

//尾插入法建表，参数为已有链表和想要的长度
template <typename T>
void LListBytail(Linklist<T> &l, int n = DefaultList)
{
    InitList(l);           //初始化为空链表
    LLnode<T> *p = l.head; //临时结点，用于创建链表
    l.len = n;             //标记链表的长度

    //通过循环生成需求长度的链表
    for (int i = 1; i <= n; i++)
    {
        LLnode<T> *tp = new LLnode<T>;
        tp->prev = p;
        tp->next = NULL;
        p->next = tp;
        p = p->next;
    }
    l.tail = p;
}
//按位置创建结点并插入数据在指定结点之后
template <typename T>
void LListInsert(Linklist<T> &l, int n, T &dt)
{
    //若插入位置超过链表长度，报错并结束函数
    if (n > l.len)
    {
        cout << "LinkList is too short" << endl;
        return;
    }
    else if (n == l.len)
    {
        LLnode<T> *tp = new LLnode<T>;
        tp->data = dt;
        tp->prev = l.tail;
        l.tail->next = tp;
        tp->next = NULL;
        l.tail = tp;
        l.len++;
        return;
    }

    LLnode<T> *p = l.head;
    //循环至相应节点处
    for (int i = 0; i < n; i++)
    {
        p = p->next;
    }
    //创建新结点插入节点
    LLnode<T> *tp = new LLnode<T>;
    tp->next = p->next;
    tp->prev = p;
    p->next->prev = tp;
    p->next = tp;
    tp->data = dt;
    l.len++; //链表长度加一
}

//合并两个升序链表
template <typename T>
Linklist<T> *LListMerge(Linklist<T> la, Linklist<T> lb)
{
    int count = 1;                                      //链表初始位置为 1
    Linklist<T> *lc = new Linklist<T>;                  //创建新链表
    InitList(*lc);                                      //初始化链表lc
    LLnode<T> *pa = la.head->next, *pb = lb.head->next; //将la和lb从初始位置开始遍历
    LLnode<T> *p = lc->head;
    while (pa != NULL || pb != NULL)
    {
        LLnode<T> *tp = new LLnode<T>; //创建新节点
        tp->next = NULL;
        tp->prev = p;
        if (pa == NULL) //链表la已空，应插入链表lb的下一个结点
        {
            tp->data = pb->data;
            pb = pb->next;
        }
        else if (pb == NULL) //链表lb已空，应插入链表la的下一个结点
        {
            tp->data = pa->data;
            pa = pa->next;
        }
        else if (pa->data < pb->data) //升序排列判断la和lb的当前data，插入小的一个
        {
            tp->data = pa->data;
            pa = pa->next;
        }
        else
        {
            tp->data = pb->data;
            pb = pb->next;
        }
        p->next = tp;           //将临时结点插入链表尾部
        lc->len++;              //链表长度加一
        lc->tail = p = p->next; //切换当前节点和尾结点
    }
    return lc;
}

//通过序号删除结点
template <typename T>
LLnode<T> LListDeletByNum(Linklist<T> &l, int pos)
{
    LLnode<T> rt;

    //若插入位置超过链表长度，报错并结束函数
    if (pos > l.len)
    {
        cout << "LinkList is too short" << endl;
        return rt;
    }
    //链表下标从1开始算， 小于等于0直接退出函数
    if (pos <= 0)
    {
        cout << "posision must be greater than 0" << endl;
        return rt;
    }

    //如果是尾结点，清除即可
    if (pos == l.len)
    {
        rt = *l.tail;
        rt.pos = l.len;
        LLnode<T> *p = l.tail->prev;
        delete l.tail;
        l.tail = p;
        l.len--;
        l.tail->next = NULL;
        return rt;
    }
    LLnode<T> *p = l.head;
    //循环至相应结点
    int i;
    for (i = 1; i < pos; i++)
    {
        p = p->next;
    }
    LLnode<T> *tp = p->next; //保存应删结点的指针
    rt = *tp;                //用于保存被删除的结点
    tp->next->prev = p;      //使下一结点的prev指向应删结点的prev
    p->next = tp->next;      //当前结点next指向应删结点的next
    rt = *tp;                //保存删除的的结点
    rt.pos = pos;            //纪录删除时的位置
    delete tp;               //释放空间
    l.len--;                 // 链表长度减
    return rt;
}

//通过结点data的值来删除结点
template <typename T>
LLnode<T> LListDeleteByValue(Linklist<T> &l, T val)
{
    LLnode<T> rt; //用于返回删除的结点

    LLnode<T> *p = l.head->next; //从头遍历
    int le = l.len;
    for (int i = 1; i <= le; i++)
    {
        if (p->data == val)
        {
            //如果是尾结点，清除即可
            if (p == l.tail)
            {
                rt = *p;
                rt.pos = l.len;
                l.tail = l.tail->prev;
                delete l.tail->next;
                l.len--;
                return rt;
            }
            rt = *p;
            rt.pos = i;
            LLnode<T> *tp = p->prev; //保存应删结点上一结点的指针
            tp->next = p->next;      //下一节点的prev应指向当前结点的prev
            p->prev = tp;            //当前结点next指向应删结点的next
            delete p;               //释放空间
            l.len--;                 // 链表长度减一
            return rt;
        }
        p = p->next;
    }
    return rt;
}

//链表逆序转置
template <typename T>
void LListReverse(Linklist<T> &l)
{
    int count = 0;
    LLnode<T> *first = l.head->next, *tp; //p始终指向原链表第一个结点
    while (count != l.len - 1)
    {
        LLnode<T> *p = l.tail->prev;

        //将尾结点插入需要插入的位置
        tp = l.tail;
        tp->next = first;
        tp->prev = first->prev;
        first->prev = tp;

        p->next = NULL;
        count++;
    }
}

//将指点链表指定位置的结点的data换为指定data
template <typename T>
void LListNoseSet(Linklist<T> &l, int n, T &data)
{
    //若插入位置超过链表长度，报错并结束函数
    if (n > l.len)
    {
        cout << "LinkList is too short" << endl;
        return;
    }

    LLnode<T> *p = l.head->next;
    //循环至相应节点处
    for (int i = 1; i < n; i++)
    {
        p = p->next;
    }
    p->data = data;
}

//重载操作符，方便正常输出链表
template <typename T>
ostream &operator<<(ostream &os, Linklist<T> &l)
{
    LLnode<T> *p = l.head->next;
    os << "the length of this linklist is : " << l.len << endl;
    os << "data of each node : " << endl;
    os << "[ " << endl;
    for (int i = 1; i <= l.len; i++)
    {
        os << p->data << endl;
        p = p->next;
    }
    cout << "]" << endl;
    return os;
}

template <typename T>
T &LListGetData(Linklist<T> &l, int num)
{
    LLnode<T> *p = l.head->next;
    //循环至相应节点处
    for (int i = 1; i < num; i++)
    {
        p = p->next;
    }
    return p->data;
}

#endif