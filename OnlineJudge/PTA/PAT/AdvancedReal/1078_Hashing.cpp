#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, deSize;
    cin >> deSize >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int reSize = 0;
    for(int i = max(2, deSize); !reSize ;i++)
    {
        int edge = sqrt(i);
        int j;
        for(j = 2; j <= edge; j++)
            if(i % j == 0)
                break;
        if(j == edge + 1)
            reSize = i;
    }
    vector<bool> table(reSize, 1);
    for(int i = 0; i < n; i++)
    {
        int flag = 1;
        for(int j = 0; j < reSize; j++)
        {
            if(table[(abs(arr[i]) + j * j) % reSize])
            {
                cout << (abs(arr[i]) + j * j) % reSize;
                table[(abs(arr[i]) + j * j) % reSize] = 0;
                flag = 0;
                break;
            }
        }
        if(flag)
            cout << "-";
        if(i != n - 1)
            cout << " ";
    }
    return 0;
}