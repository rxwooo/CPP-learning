#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[5];
    memset(a, 0, sizeof(a));
    int num;
    int sum0 = 0;
    int sum1 = 0;
    int sum3 = 0;
    int max4 = -1;
    int t = 0;
    cin >> t;
    while(t--)
    {   cin >> num;
        switch(num % 5)
        {
            case 0:
                if(num % 2 == 0)
                {
                    a[0] ++;
                    sum0 += num;
                }  
                break;
            case 1:
                a[1] ++;
                if(a[1] % 2 == 1)
                    sum1 += num;
                else
                    sum1 -= num;
                break;
            case 2:
                a[2] ++;
                break;
            case 3:
                a[3] ++;
                sum3 += num;
                break;
            case 4:
                a[4] ++;
                max4 = max(max4, num);
                break;
            default: ;
        }
    }
    if(a[0] == 0)
        cout << "N ";
    else
        cout << sum0 << " ";
    if(a[1] == 0)
        cout << "N ";
    else
        cout << sum1 << " ";
    if(a[2] == 0)
        cout << "N ";
    else
        cout << a[2] << " ";
    if(a[3] == 0)
        cout << "N ";
    else
        printf("%.1f ", (float)sum3/a[3]);
    if(a[4] == 0)
        cout << "N ";
    else
        cout << max4 << endl;
    return 0;
}
