//归一化处理

// 输入格式
// 从标准输入读入数据。
// 第一行包含一个整数n，表示待处理的整数个数。
// 第二行包含空格分隔的n个整数，依次表示。

// 输出格式
// 输出到标准输出。
// 输出共n行，每行一个浮点数，依次表示按上述方法归一化处理后的数据。

//sample input
// 7
// -4 293 0 -22 12 654 1000

//sample output
// -0.7485510379073613
// 0.04504284674812264
// -0.7378629047806881
// -0.7966476369773906
// -0.7057985054006686
// 1.0096468614303775
// 1.9341703768876082
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double ave = 0;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i ++)
    {
        int num;
        cin >> num;
        nums[i] = num;
        ave += num / n;
    }

    double d = 0;
    for(int num: nums)
        d += (num - ave) * (num - ave) / n;
    for(int num: nums)
    {
        printf("%.16lf\n", (num - ave) / sqrt(d));
    }

    return 0;
}