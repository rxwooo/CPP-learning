#include <bits/stdc++.h>
using namespace std;

struct node
{
    char name[4];
    int num;
} poke[54];

char s[6] = "SHCDJ";
int arr[54];

bool cmp(node a, node b)
{
    return a.num < b.num;
}

void format()
{
    int count = 0;
    for (int i = 0; i < 52; i++)
    {
        poke[i].num = i;
        sprintf(poke[i].name, "%c%d", s[i / 13], i % 13 + 1);
    }
    sprintf(poke[52].name, "J1");
    sprintf(poke[53].name, "J2");
}

int main()
{
    format();
    int n;
    cin >> n;
    for (int i = 0; i < 54; i++)
        cin >> arr[i];

    while (n--)
    {
        for (int i = 0; i < 54; i++)
        {
            poke[i].num = arr[i];
        }
        sort(poke, poke + 54, cmp);
    }
    for (int i = 0; i < 53; i++)
    {
        cout<<poke[i].name<<" ";
    }
    cout<<poke[53].name;

    return 0;
}