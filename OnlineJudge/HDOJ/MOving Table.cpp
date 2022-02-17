#include <bits/stdc++.h>
using namespace std;

//目的是求最大的路劲重复数
int main()
{
    int c; //测试样例数
    cin >> c;
    while (c--)
    {
        int n;
        int a[201] = {0};
        cin >> n; // 输入桌子数量
        int max = 0;

        //将每次搬运任务存入结构体数组，目的是求路线重复最大值
        for (int j = 0; j < n; j++)
        {
            int ks, js; //单次开始结束的时间
            cin >> ks >> js;

            //确保开始小于结束
            if (ks > js)
            {
                int temp = ks;
                ks = js;
                js = temp;
            }

            //将本次搬运的所经过的路径加一
            for (int k = (ks + 1) / 2; k <= (js + 1) / 2; k++)
            {
                a[k]++;
                if (a[k] > max)
                    max = a[k];
            }
        }
        cout << max * 10 << endl;
    }
}