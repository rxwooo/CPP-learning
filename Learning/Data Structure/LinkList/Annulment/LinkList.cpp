#include "LinkList.h"
using namespace std;

/*
    本程序目的是测试链表的可用性，暂不追求效率
    本程序将两个链表分别初始化为1到19的奇数和0到18的偶数
    随后同两种方法分别删除两个链表的末尾结点
    再分贝在两个链表后插入其他数据
    最后新建一个链表存储两个链表升序合并后的新链表并输出
*/

/*
    sample output:

    
    List 1 :
    the length of this linklist is : 9
    data of each node :
    [ 1, 3, 5, 7, 9, 11, 13, 15, 17, ]

    List 2 :
    the length of this linklist is : 9
    data of each node :
    [ 0, 2, 4, 6, 8, 10, 12, 14, 16, ]

    List 3 :
    the length of this linklist is : 20
    data of each node :
    [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 20, 22, ]
*/

int main()
{
    Linklist<int> l1, l2;
    InitList(l1); //初始化l1
    InitList(l2); //初始化l2

    LListBytail(l1, 10); //将l1设置长度为10并分配空间
    LListBytail(l2, 10); //将l2设置长度为10并分配空间

    //将l1设置为1到19的奇数
    for (int i = 0; i < 10; i++)
    {
        int n = i * 2 + 1;
        LListNoseSet(l1, i + 1, n);
    }
    //将lw设置为0到18的偶数
    for (int i = 0; i < 10; i++)
    {
        int n = i*2;
        LListNoseSet(l2, i + 1, n);
    }

    LListDeletByNum(l1, 10);    //删除l1中的第10个结点
    LListDeleteByValue(l2, 18); //删除l2中data为18的结点

    int n1 = 20, n2 = 22;
    LListInsert(l1, 9, n1); //在l1第九个结点后插入一个data为20的结点
    LListInsert(l2, 9, n2); //在l2第九个结点后插入一个data为22的结点

    //合并l1和l2到l3
    Linklist<int> *l3 = LListMerge(l1, l2);

    cout << "List 1 :" << endl;
    cout << l1 << endl;
    cout << "List 2 :" << endl;
    cout << l2 << endl;
    cout << "List 3 :" << endl;
    cout << (*l3) << endl;
    return 0;
}
