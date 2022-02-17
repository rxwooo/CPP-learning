#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if(n==0) break;
        int jp[1001] = {0}, cn[1001] = {0};
        int h = 0, j = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> cn[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> jp[i];
        }
        sort(jp, jp + n);
        sort(cn, cn + n);
        for (int i = 0; i < n; i++)
        {
            if (jp[i] > cn[i]) j+=2;
                
            else if (cn[i] > jp[i]) h+=2;

            else{
                j++;
                h++;
            }  
        }
        cout<<h<<" vs "<<j<<endl;
    }
}