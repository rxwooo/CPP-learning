#include <bits/stdc++.h>
using namespace std;

struct node
{
    char nm[15];
    int age;
    double sc;
};

bool cmp(node &n1, node &n2)
{
    if (n1.sc == n2.sc)
        if (n1.age == n2.age)
        {
            int fg = strcmp( n1.nm , n2.nm);
            if(fg > 0)
                return 0;
            else 
                return 1;

        }
        else
            return n1.age < n2.age;
    else
        return n1.sc > n2.sc;
}

int main()
{
    int n;
    while (cin >> n)
    {
        node st[110];
        for (int i = 0; i < n; i++)
        {
            cin >> st[i].nm >> st[i].age >> st[i].sc;
        }
        sort(st,st+n,cmp);
        for (int i = 0; i < n; i++)
        {
            printf("%s %d %.2f\n",st[i].nm,st[i].age,st[i].sc);
        }
    }
}