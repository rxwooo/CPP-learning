#include<bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    int x = 0;
    int y = 0;
    while(cin >> c)
    {
        if(c == 'R')
            x++;
        else if(c == 'L')
            x--;
        else if(c == 'U')
            y++;
        else y--;
    }
    cout << "(" << x << "," << y << ")" << endl;
    return 0;
}