#include<bits/stdc++.h>
using namespace std;

void arrSwap(int arr[], int a, int b)
{
    if(a == b) return;
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

template<class T>
int length(T& arr)
{
    return sizeof(arr)/sizeof(arr[0]);
}

void twoClass(int arr[], int l, int r, int edge)
{
    int less = l, pos = l;
    while(pos < r)
    {
        if(arr[pos] <= edge)
        {
            arrSwap(arr, less, pos);
            less++;
        }
        pos++;
    }
    return;
}

void threeClass(int arr[], int l, int r, int edge)
{
    int lar = r;
    int less = l, pos = l;
    while(pos < r && pos < lar)
    {
        if(arr[pos] < edge)
        {
            arrSwap(arr, less, pos);
            less++;
        }
        if(arr[pos] > edge)
        {
            lar--;
            arrSwap(arr, lar, pos);
            continue;
        }
        pos++;
    }
}

int main()
{
    int arr[] = {4, 5, 3, 6, 2, 5, 1};
    int len = length(arr);
    twoClass(arr, 0, len, 1);
    for(int i = 0; i < len; i++)
        cout << arr[i] << endl;
    return 0;
}