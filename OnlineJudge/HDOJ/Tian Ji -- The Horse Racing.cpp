#include <bits/stdc++.h>
using namespace std;

int tj[1010], kin[1010];
int tjbk, kinbk;
int sum;

//使马的速度降序排列
bool cmp(int a, int b)
{
    return a > b;
}

//使用递归进行比赛，参数分别为当前tianji的马，king的马，当前比分，递归终点返回最终比分
int race(int tjh, int kinh, int re)
{
    //最后的比赛设为递归终点
    if (tjh == tjbk)
    {
        if (tj[tjh] > kin[kinh])
        {
            re++;
        }
        else if (tj[tjh] < kin[kinh])
        {
            re--;
        }
        return re;
    }

    if (tj[tjh] > kin[kinh]) //如果tianji的当前速度大于king，直接赢
    {
        re++;
        return race(tjh + 1, kinh + 1, re);
    }
    else if (tj[tjh] < kin[kinh]) //如果tianji当前会输，让最差的马代替输
    {
        re--;
        tjbk--;
        return race(tjh, kinh + 1, re);
    }
    else if (tj[tjh] == kin[kinh]) //如果当前是平局，看双方当前最差的马
    {
        if (tj[tjbk] <= kin[kinbk]) //如果最差的马相比也会输，不如让他输给当前king最好的马
        {
            if(tj[tjbk] < kin[kinh]) re--;
            tjbk--;
            return race(tjh, kinh + 1, re);
        }
        else if (tj[tjbk] > kin[kinbk]) //如果最差的马能赢，就赢下，然后当前马继续参与比较
        {
            tjbk--;
            kinbk--;
            re++;
            return race(tjh, kinh, re);
        }
        /*
        else //如果当前马也会打平，直接打平，当前马继续比赛
        {
            tjbk--;
            kinbk--;
            return race(tjh, kinh, re);
        }
        */
    }
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        sum = 0;
        tjbk = kinbk = n;
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> tj[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> kin[i];
        }
        sort(tj + 1, tj + n + 1, cmp);
        sort(kin + 1, kin + n + 1, cmp);
        sum = race(1, 1, 0);
        cout<<sum*200<<endl;
    }
}