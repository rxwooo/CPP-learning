#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[1010];
    int k, b[1010];
    while (scanf("%s%d", a, &k) != EOF)
    {
        int l;
        l = strlen(a);
        int i;
        for (i = 0; i < l; i++)
        {
            b[i] = a[i] - '0';
        }
        for (i = 0; i < l; i++)
        {
            b[i + 1] = (b[i] * 10 + b[i + 1]) % k;
        }
        printf("%d\n", b[l - 1]);
    }
    return 0;
}