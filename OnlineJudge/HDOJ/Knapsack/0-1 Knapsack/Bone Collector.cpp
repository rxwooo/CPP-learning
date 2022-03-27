#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int bg[1010]; //这是背包
        int val[1010], wei[1010];//val指的是每个物品的价值，wei指的是每个物品的代价
        int n, bag; //物品数量、背包大小
        memset(bg,0,sizeof(bg));
        cin >> n >> bag;

        //分别依次输入每个物品的价值和代价
        for (int i = 1; i <= n; i++)
            cin >> val[i];
        for (int i = 1; i <= n; i++)
            cin >> wei[i];

        //动态规划过程，不用管，前面的改好就可以了
        for (int i = 1; i <= n; i++)
            for (int j = bag; j >= wei[i]; j--)
                bg[j] = max(bg[j], bg[j - wei[i]] + val[i]);
        
        //输出背包内容
        cout<<bg[bag]<<endl;
    }
}