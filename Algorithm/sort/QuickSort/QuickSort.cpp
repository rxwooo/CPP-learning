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

void threeClass(int arr[], int l, int r, int edge, int cut[])
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
    cut[0] = less;
    cut[1] = lar;
    return ;
}

int twoClass(int arr[], int l, int r, int edge)
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
    return less;
}

void QuickSort(int arr[], int l, int r)
{
    if(r - l == 1 || r == l) return ; // 只排序一个数或空区间
    int ran = rand()%(r - l) + l;
    int* cut = new int[2];

    arrSwap(arr, ran, r - 1);
    threeClass(arr, l, r - 1, arr[r - 1], cut);
    arrSwap(arr, cut[0], r - 1);
    QuickSort(arr, l, cut[0]);
    QuickSort(arr, cut[1], r);
}

int main()
{
    srand(time(NULL));
    int arr[7] = {4, 5, 3, 6, 2, 5, 1};
    int len = length(arr);
    QuickSort(arr, 0, len);
    for(int i = 0; i < len; i++)
        cout << arr[i] << endl;
    return 0;
}