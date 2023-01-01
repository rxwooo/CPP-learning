#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;

    int minN = 0x3f3f3f3f;
    int maxN = -1;
    while(n--)
    {
        int num;
        cin >> num;
        minN = min(minN, num);
        maxN = max(maxN, num);
        arr.push_back(num);
    }

    bool spChk = (maxN - minN) >= 33;
    if(spChk)
    {
        int newA = minN + 33;
        for(int num: arr)
            if(num != minN)
            if(num < newA || num > newA + 25)
            {
                cout << 0 << endl;
                return 0;
            }
        int dis = minN - 32;
        for(int num: arr)
        {
            char c = num - dis;
            cout << c ;
        }
        cout << endl;
    }
    else //没有空格
    {
        if(maxN - minN > 25)
        {
            cout << 0 << endl;
            return 0;
        }
        int less = minN - 65;
        int large = 90 + 999 - maxN;
        cout << large + less + 1 << endl;
    }
    return 0;
}