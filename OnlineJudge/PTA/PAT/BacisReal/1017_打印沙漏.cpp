#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char ch;
    cin >> n >> ch;
    if(n == 0) 
        return 0;
    if(n == 1)
    {
        cout << ch << endl;
        cout << 0 << endl;
        return 0;
    }
    n --;
    int level = 1;
    int num = 3;
    while(n > num * 2)
    {
        level++;
        n -= num*2;
        num += 2;
    }
    for(int i = 0; i < level; i++)
    {
        for(int j = 0; j < i; j++)
            cout << " ";
        for(int j = 0; j < (level - i) * 2 - 1; j++)
            cout << ch;
        cout << endl;
    }
    for(int i = level - 2; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
            cout << " ";
        for(int j = 0; j < (level - i) * 2 - 1; j++)
            cout << ch;
        cout << endl;
    }
    cout << n << endl;
    return 0;
}