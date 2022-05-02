#include <bits/stdc++.h>
using namespace std;

int arr[10010];
bool cmp (int a, int b)
{
    return a > b;
}

void arrSwap(int arr[], int a, int b)
{
    if(a == b) return;
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

int minMax(vector<int> &a, int k, int x)
{
    int len = a.size();
    for(int i = 0; i < len; i++) 
        arr[i] = a[i];
    sort(arr, arr + len, cmp);
    int count = 0;
    while(count < k)
    {
        arr[0] -= x;
        count ++;
        int dis = min(count, len);
        sort(arr, arr + dis, cmp);
    }
    return arr[0];
}

int main()
{
    vector<int> tp = {1};
    cout << minMax(tp,3,2) << endl;
    return 0;
}