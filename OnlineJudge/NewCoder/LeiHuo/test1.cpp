#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int gong1[6], gong2[6];
    int row[6];
    int col[6][6];
    int count = 0;
    while(n--)
    {
        char ch;
        int c;
        int flag = 0;
        
        memset(col, 0, sizeof(col));
        for(int i = 0; i < 6; i++)
        {
            if(i % 2 == 0)
            {
                memset(gong1, 0, sizeof(gong1));
                memset(gong2, 0, sizeof(gong2));
            }
            getchar();
            memset(row, 0, sizeof(row));
            for(int j = 0; j < 6; j++)
            {
                ch = getchar();
                c = ch - '0';
                // if(c > 6 || c < 1)
                // {
                //     flag = 1;
                //     continue;
                // } 

                if(row[c - 1] == 1) flag = 1;
                row[c - 1] = 1;

                if(j < 3)
                {
                    if(gong1[c - 1] == 1) flag = 1;
                    gong1[c - 1] = 1;
                }
                else
                {
                    if(gong2[c - 1] == 1) flag = 1;
                    gong2[c - 1] = 1;
                }

                if(col[i][j] == 1) flag = 1;
                col[i][j] = 1;
            }
        }
        if(flag == 0)
            count ++;
    }
    cout << count << endl;
    return 0;
}