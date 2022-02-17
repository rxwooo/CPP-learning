#include <bits/stdc++.h>
using namespace std;

int ck[1110];
int vis[1110];

int main()
{
    int n, m;
    while (cin >> m >> n)
    {
        memset(ck, 0, sizeof(ck));
        memset(vis, 0, sizeof(vis));
        ck[0] = 0;
        for (int i = 0; i <= m; i++)
        {
            if (ck[i] == 0)
                for (int j = 1; j <= n; j++)
                {
                    if (i + j > m)
                        break;
                    ck[i + j] = 1;
                }
        }
        int count = 0;
        {
            for (int i = 1; i <= n; i++)
            {
                if (ck[m - i] == 0)
                {
                    count++;
                    vis[m - i] = 1;
                }
            }
        }
        if (count)
        {
            for (int i = 1; i <= n; i++)
            {
                if (vis[m - i])
                {
                    cout << i;
                    if (--count)
                        cout << " ";
                }
            }
            cout << endl;
        }
        else
            cout << "none" << endl;
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

int sg[1110];
int a[1110];
int vis[1110];
int m,n;

int g(int x)
{
    if(sg[x]!=-1)
        return sg[x];
    int mex[1110];
    memset(mex, 0, sizeof(mex));
    for(int i = 1  ; i<=n; i++)
    {
        int t = x - a[i];
        if( t < 0 )
            break;
        if(sg[t]==-1)
            sg[t] = g(t);
        mex[sg[t]] = 1;
    }
    for(int i = 0; ;i++)
        if(!mex[i])
            return i;
}  

int main()
{
    for(int i = 0;i < 1110; i++) a[i] = i;
    while(cin>>m>>n)
    {
        memset(sg, -1, sizeof(sg));
        memset(vis,0,sizeof(vis));                                                                                                       
        sg[m] = g(m);
        int count = 0;
        {
            for (int i = 1; i <= n; i++)
            {
                if (sg[m - i] == 0)
                {
                    count++;
                    vis[m - i] = 1;
                }
            }
        }
        if (count)
        {
            for (int i = 1; i <= n; i++)
            {
                if (vis[m - i])
                {
                    cout << i;
                    if (--count)
                        cout << " ";
                }
            }
            cout << endl;
        }
        else
            cout << "none" << endl;
    }
    return 0;
} 
*/