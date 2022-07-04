#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    int next;
};
// 傻逼题目
int main()
{
    int first, n, k;
    int count = 0;
    node dp[100000];
    cin >> first >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int index;
        cin >> index;
        if (index > 99999)
            cin >> index >> index;
        cin >> dp[index].data >> dp[index].next;
    }
    vector<int> list;
    for (int i = 0; i < n; i++)
    {
        list.push_back(first);
        first = dp[first].next;
        count ++;
        if(first == -1)
            break;
    }
    int pos = 0;
    while (pos + k <= count)
    {
        for (int i = pos + k - 1; i >= pos; i--)
        {
            printf("%05d %d ", list[i], dp[list[i]].data);
            if (i == pos)
            {
                if (pos + k == count)
                    printf("-1");
                else
                    printf("%05d\n", list[pos + k]);
            }
            else
                printf("%05d\n", list[i - 1]);
        }
        pos += k;
    }
    while (pos < count)
    {
        printf("%05d %d ", list[pos], dp[list[pos]].data);
        if (pos == count - 1)
            printf("-1");
        else
            printf("%05d\n", list[pos + 1]);
        pos++;
    }
    return 0;
}