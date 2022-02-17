#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x1, x2, y1, y2;
    while (cin >> x1 >> y1 >> x2 >> y2)
    {
        double ans = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
        printf("%.2f\n", ans);
    }
    return 0;
}