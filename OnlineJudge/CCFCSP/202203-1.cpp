#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> left(n + 1, 0);
    vector<int> init(n + 1, 0);
    int count = 0;
    for(int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        if(b == 0)
        {
            init[a] = 1;
            left[a] = 1;
        }
        else if(left[b] == 1)
        {
            init[a] = 1;
            init[b] = 1;
            left[a] = 1;
        }
        else
        {
            left[a] = 1;
            count ++;
        }
    }
    cout << count << endl;
    return 0;
}