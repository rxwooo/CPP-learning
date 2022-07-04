#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, double> poly;
    int n;
    int maxN = -1;
    cin >> n;
    while(n--)
    {
        int N;
        double data;
        cin >> N >> data;
        if(abs(data - 0.0) < 0.000001)
            continue;
        poly[N] += data;
        maxN = max(maxN, N);
    }
    cin >> n;
    while(n--)
    {
        int N;
        double data;
        cin >> N >> data;
        if(abs(data - 0.0) < 0.000001)
            continue;
        poly[N] += data;
        if(poly[N] < 0.000001)
            poly.erase(N);
        maxN = max(maxN, N);
    }
    cout << poly.size();
    if(poly.size() != 0)
    {
        while(maxN >= 0)
        {
            if(poly.find(maxN) != poly.end())
                printf(" %d %.1f", maxN, poly[maxN]);
            maxN--;
        }
    }
    cout << endl;
    return 0;
}