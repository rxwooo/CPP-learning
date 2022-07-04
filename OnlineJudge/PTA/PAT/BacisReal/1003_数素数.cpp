#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;
    int count = 0;
    for(int i = 2; ; i++)
    {
        int edge = sqrt(i);
        bool flag = 1;
        for(int j = 2; j <= edge; j++)
            if(i % j == 0)
            {
                flag = 0;
                break;
            }
        if(flag)
        {
            count ++;
            if(count <= n && count >= m)
            {
                cout << i;
                if((count - m + 1) % 10 == 0)
                    cout << endl;
                else
                    cout << " ";
            }
                
            if(count == n)
                break;
        }
    }
    return 0;
}