#include<bits/stdc++.h>
using namespace std;

int main()
{
    int re[2][3]; //re[][0] ying; re[][1]ping; re[][2]shu
    int win[2][3];//win[][0] jian dao; win[][1] chuizi; win[][2] bu
    memset(re, 0, sizeof(re));
    memset(win, 0, sizeof(win));
    int n;
    cin >> n;
    while(n --)
    {
        char jia, yi;
        cin >> jia >> yi;
        if(jia == yi)
        {
            re[0][1] ++;
            re[1][1] ++;
        }
        else if(jia == 'B' && yi == 'C')
        {
            re[0][0]++;
            re[1][2]++;
            win[0][2]++;
        }
        else if(jia == 'B' && yi == 'J')
        {
            re[0][2]++;
            re[1][0]++;
            win[1][0]++;
        }
        else if(jia == 'C' && yi == 'B')
        {
            re[0][2]++;
            re[1][0]++;
            win[1][2]++;
        }
        else if(jia == 'C' && yi == 'J')
        {
            re[0][0]++;
            re[1][2]++;
            win[0][1]++;
        }
        else if(jia == 'J' && yi == 'C')
        {
            re[0][2]++;
            re[1][0]++;
            win[1][1]++;
        }
        else if(jia == 'J' && yi == 'B')
        {
            re[0][0]++;
            re[1][2]++;
            win[0][0]++;
        }
    }
    cout << re[0][0] << " " << re[0][1] << " " << re[0][2] << endl;
    cout << re[1][0] << " " << re[1][1] << " " << re[1][2] << endl;
    int minJ = max(win[0][1], max(win[0][2], win[0][0]));
    if(minJ == win[0][2])
        cout << "B";
    else if(minJ == win[0][1])
        cout << "C";
    else
        cout << "J";
    cout << " ";
    int minY = max(win[1][1], max(win[1][2], win[1][0]));
    if(minY == win[1][2])
        cout << "B";
    else if(minY == win[1][1])
        cout << "C";
    else
        cout << "J";
    cout << endl;
    return 0;
}