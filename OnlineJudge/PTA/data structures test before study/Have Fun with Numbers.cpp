#include <bits/stdc++.h>
using namespace std;

char od[22], ck[22];
int odn[10], ckn[10];

int main()
{
    memset(od, 0, sizeof(od));
    cin >> (od + 1);
    od[0] = ck[0] = '0';
    int tp = 0;
    for (int i = strlen(od) - 1; i > 0; i--)
    {
        int a = od[i] - '0';
        odn[a]++;
        a *= 2;
        ck[i] = (a + tp) % 10 + '0';
        tp = (a + tp) - ck[i] + '0';
        tp /= 10;
        ckn[ck[i] - '0']++;
    }
    if(tp==1) ck[0] = '1' ;
    int count = 0;
    for (int i = 0; i < 10; i++)
        if (ckn[i] == odn[i])
            count++;

    //if(strlen(od)!=strlen(ck)) { cout << "No" << endl; cout << (ck[0] == '0' ? (ck + 1) : ck) << endl; return 0; }
    cout << (count == 10 ? ("Yes") : ("No")) << endl;
    cout << (ck[0] == '0' ? (ck + 1) : ck) << endl;
    return 0;
}