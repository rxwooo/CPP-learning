#include <bits/stdc++.h>
using namespace std;

//每个人作为一个结构体。包含自己的序号和信息
struct person
{
    int num; //玩家序号
    int mm; //玩家信息
};

template <class T>
struct LLnode
{
    T data;       //结点数据
    LLnode *next; //下一节点的指针
    LLnode *prev; //上一节点的指针
};

//链表结构体，引导一个链表,该链表包含一个空的头结点
template <class T>
struct Linklist
{
    Linklist() : len(0) {} //保证链表初始长度为 0
    LLnode<T> *head;       //头结点
    LLnode<T> *tail;       //尾结点
    int len;               //链表长度
};


//初始化链表，将链表清空并初始化为空链表
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

//返回链表长度
template <class T>
int LListLength(Linklist<T> &l)
{
    return l.len;
} 

//按位置创建结点并插入数据在指定结点之后
template <class T>
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


//通过序号删除结点
template <class T>
void LListDeletByNum(Linklist<T> &l, int pos)
{
    //若插入位置超过链表长度，报错并结束函数
    if (pos > l.len)
    {
        cout << "LinkList is too short" << endl;
        return;
    }
    //链表下标从1开始算， 小于等于0直接退出函数
    if (pos <= 0)
    {
        cout << "posision must be greater than 0" << endl;
        return;
    }

    //如果是尾结点，清除即可
    if (pos == l.len)
    {
        LLnode<T> *p = l.tail->prev;
        delete l.tail;
        l.tail = p;
        l.len--;
        l.tail->next = NULL;
        return;
    }
    LLnode<T> *p = l.head;
    //循环至相应结点
    for (int i = 1; i < pos; i++)
    {
        p = p->next;
    }
    LLnode<T> *tp = p->next; //保存应删结点的指针
    tp->next->prev = p;
    p->next = tp->next; //当前结点next指向应删结点的next
    delete tp;          //释放空间
    l.len--;            // 链表长度减一
}

//获取结点在指定链表里的坐标并返回
template <class T>
int LListGetPos(Linklist<T> &l, LLnode<T> *ln)
{
    LLnode<T> *tp = l.head;
    if(l.len == 1) if(tp->next==ln) return 1;
    for(int i=1;i<l.len;i++)
    {
        tp = tp->next;
        if(tp==ln)
            return i;
    }
    return -1;
}

//引导输入信息，创建约瑟夫环链表
template <class T>
Linklist<T> *CreatJoseph(int num)
{
    cout<<"        please input the message of each player : ";
    Linklist<person> *l = new Linklist<person>;
    InitList(*l);
    for (int i = 1; i <= num; i++)
    {
        int n;
        cin >> n;
        person p;
        p.num = i;
        p.mm = n; //每个玩家结点保存的往后数的信息
        LListInsert(*l, LListLength(*l), p);
    } 
    cout<<endl;
    return l;
}

//引导输入游戏人数
int JosephPlayer(int &n)
{
    cout << endl;
    cout << "        please input the positive integer of players or other to exit : ";
    cin >> n;
    cout<<endl;
    return n > 0;
}

//开始约瑟夫环并引导输入游戏开始的坐标
int JosephBegin(int n)
{
    int m;
    cout << "       please input the number of beginning of game : " ;
    cin >> m;
    cout << endl;
    return m%n==0?n:m; //若m大于总人数，则返回其与总人数的模
}


//处理信息并输出出队序列
template <typename T>
void JosephOutput(Linklist<T> *l, int m)
{
    cout<<"        the order of outline is : ";
    LLnode<person> *tp = l->head->next; //临时结点保存首结点
    while (LListLength(*l))
    {
        for (int i = 1; i < m; i++)
        {
            if (tp->next)
                tp = tp->next;
            else
                tp = l->head->next;
        }
        m = tp->data.mm;
        cout << tp->data.num << " ";
        int pos = LListGetPos(*l, tp); //获得出队的结点的坐标
        //若下一结点为尾结点，则返回头结点
        if (tp->next)
            tp = tp->next;
        else
            tp = l->head->next;
        LListDeletByNum(*l, pos); //将出队的结点从链表删除
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;
}

void JosethMain()
{
    int n, m; //分别保存约瑟夫环的人数和报数的上限值
    Linklist<person> *l;//创建循环链表保存每个玩家结点
    while (JosephPlayer(n))
    {
        m = JosephBegin(n); //获得首轮开始的序号
        l = CreatJoseph<person>(n);//获得创建的链表
        JosephOutput(l,m);//根据创建的约瑟夫环输出出队序列
    }
}

int main()
{
    JosethMain();
    return 0;
}