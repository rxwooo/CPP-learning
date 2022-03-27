#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int repeat = 0;
    int pos = 0;
    char str[51][1010];
    memset(str, 0, sizeof(str));
    cin >> n;
    getchar();
    for(int i = 0; i < n;)
    {
        char c;
        c = getchar();
        if(c == '\n')
        {
            i++;
            pos = 0;
            repeat = 0;
            continue;
        }
        if(pos == 0)
        {
            str[i][pos] = c;
            pos = 1;
            continue;
        }
        if(str[i][pos - 1] == c)
            repeat ++;
        if(repeat == 2) 
        {
            if(str[i][pos - 1] == c)
                repeat --;
            else
                repeat = 0;
            continue;
        }
        str[i][pos] = c;
        pos++;
    }
    for(int i = 0; i < n; i++)
    {
        cout << str[i] << endl;
    }
    return 0;
}