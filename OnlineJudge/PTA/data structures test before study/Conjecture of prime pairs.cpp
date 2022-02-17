#include <bits/stdc++.h>
using namespace std;

int tp1, tp2;
int isprime(int);

int main()
{
    int n;
    while (cin >> n)
    {
        int count=0;
        tp1=2;
        for(int i=3;i<=n;i++)
        {
            if(isprime(i))
            {
                tp2=i;
                if(tp2-tp1==2)
                {
                    count++;
                }
                tp1=tp2;
            }
        }
        cout<<count<<endl;
    }
}

int isprime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}