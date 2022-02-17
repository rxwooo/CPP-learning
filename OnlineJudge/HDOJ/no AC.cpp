#include <bits/stdc++.h>
using namespace std;

//节目，自带属性开始结束的时间
struct node
{
    int bg, ed;
};

//排序，以结束时间为主排序，相同则以先开始时间排序
bool cmp(node n1, node n2)
{
    if (n1.ed == n2.ed)
        return n1.bg < n2.bg;
    return n1.ed < n2.ed;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        node pg[110]; //存储节目序列
        for (int i = 0; i < n; i++)
        {
            cin >> pg[i].bg >> pg[i].ed;
        }
        sort(pg, pg + n, cmp);
        int nowtime = 0;
        int count = 0;

        //遍历数组，开始时间比当前时间晚就看
        for (int i = 0; i < n; i++)
        {
            if (nowtime <= pg[i].bg)
            {
                nowtime = pg[i].ed;
                count++;
    
        }
        cout << count << endl;
    }
}