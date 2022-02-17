#include <bits/stdc++.h>
using namespace std;

struct node
{
    int n1, n2, n3;
    int st;
};
int n1, n2, n3;
int vis[110][110];

int bfs();
bool ck(node n)
{
    if (n.n1 == n.n2 && n.n3 == 0)
        return 1;
    if (n.n1 == n.n3 && n.n2 == 0)
        return 1;
    if (n.n3 == n.n2 && n.n1 == 0)
        return 1;
    return 0;
}

int main()
{
    while (cin >> n1 >> n2 >> n3, n1)
    {
        memset(vis, 0, sizeof(vis));
        int re = bfs();
        if(re != -1)
            cout<<re<<endl;
        else 
            cout<<"NO"<<endl;
    }
}

int bfs()
{
    node cu, nex;
    queue<node> qu;
    cu.n1 = n1;
    cu.n2 = 0;
    cu.n3 = 0;
    cu.st = 0;
    vis[0][0] = 1;
    qu.push(cu);
    while (!qu.empty())
    {
        cu = qu.front();
        qu.pop();
        if (ck(cu))
            return cu.st;

        //n1 to n2
        if (cu.n1 > (n2 - cu.n2))
        {
            nex.n1 =cu.n1- (n2 - cu.n2);
            nex.n2 = n2;
        }
        else
        {
            nex.n2 = cu.n2 +  cu.n1;
            nex.n1 = 0;
        }
        nex.n3 = cu.n3;
        if (!vis[nex.n2][nex.n3])
        {
            vis[nex.n2][nex.n3] = 1;
            nex.st = cu.st + 1;
            qu.push(nex);
        }

        //n1 to n3
        if (cu.n1 > (n3 - cu.n3))
        {
            nex.n1 = cu.n1-( n3 - cu.n3);
            nex.n3 = n3;
        }
        else
        {
            nex.n3 = cu.n3 + cu.n1;
            nex.n1 = 0;
        }
        nex.n2 = cu.n2;
        if (!vis[nex.n2][nex.n3])
        {
            vis[nex.n2][nex.n3] = 1;
            nex.st = cu.st + 1;
            qu.push(nex);
        }

        //n2 to n1
        nex.n1 = cu.n1+cu.n2;
        nex.n2 = 0;
        nex.n3 = cu.n3;
        if (!vis[nex.n2][nex.n3])
        {
            vis[nex.n2][nex.n3] = 1;
            nex.st = cu.st + 1;
            qu.push(nex);
        }

        //n3 to n1
        nex.n1 = cu.n1+cu.n3;
        nex.n3 = 0;
        nex.n2 = cu.n2;
        if (!vis[nex.n2][nex.n3])
        {
            vis[nex.n2][nex.n3] = 1;
            nex.st = cu.st + 1;
            qu.push(nex);
        }

        //n2 to n3
        if(cu.n2>(n3-cu.n3))
        {
            nex.n2 = cu.n2 - (n3-cu.n3);
            nex.n3 = n3;
        }
        else
        {
            nex.n3 = cu.n3 + cu.n2;
            nex.n2 = 0;
        }
        nex.n1 = cu.n1;
        if(!vis[nex.n2][nex.n3])
        {
            nex.st = cu.st + 1;
            qu.push(nex);
        }

        //n3 to n2
        if(cu.n3>(n2-cu.n2))
        {
            nex.n3 = cu.n3 - (n2-cu.n2);
            nex.n2 = n2;
        }
        else
        {
            nex.n2 = cu.n2 + cu.n3;
            nex.n3 = 0;
        }
        nex.n1 = cu.n1;
        if(!vis[nex.n2][nex.n3])
        {
            nex.st = cu.st + 1;
            qu.push(nex);
        }
    }
    return -1;
}