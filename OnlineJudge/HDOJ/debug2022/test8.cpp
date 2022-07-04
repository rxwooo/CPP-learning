#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        long long bg, ed, time;
        cin >> bg >> ed >> time;
        if(time == 0)
            cout << bg << endl;
        else if(bg == ed)
            cout << bg << endl;
        else if(bg * ed < 0)
            cout << (time) % (ed - bg + 1) + bg << endl;
        else
            cout << (time) % (ed - bg + 1) + bg << endl;
    }
    return 0;
}