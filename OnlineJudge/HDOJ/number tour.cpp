#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        
        //用数组表示数塔，第几层就有几个数
        long long num[110][110];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                cin >> num[i][j];
           
        //从倒数第二层开始，每个节点都要加上子节点中较大的那一个
        for (int i = n - 1; i >= 1; i--)
            for (int j = 1; j <= i; j++)
                num[i][j] += max(num[i + 1][j], num[i + 1][j + 1]);

        cout<<num[1][1]<<endl; //输出最终的的根节点
    }
}