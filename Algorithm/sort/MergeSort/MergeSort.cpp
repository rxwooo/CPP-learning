#include<bits/stdc++.h>
using namespace std;

void MergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int r);

void arr_swap(int arr[], int a, int b)
{
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

template<class T>
int length(T& arr)
{
    return sizeof(arr)/sizeof(arr[0]);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    MergeSort(arr, 0, length(arr) - 1);
    for(int i = 0; i < length(arr); i++)
        cout << arr[i] << endl;
}

void merge(int arr[], int l, int r)
{
    int mid = l + ((r - l) >> 1);
    int p1 = l, p2 = mid+1, i = 0;
    int *arr2 = new int [r - l + 1];
    while(p1 <= mid && p2 <= r)
        arr2[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
    while(p1 <= mid)
        arr2[i++] = arr[p1++];
    while(p2 <= r);
        arr2[i++] = arr[p2++];
    for(i = 0; i < r - l + 1; i++)
        arr[i + l] = arr2[i];
    delete arr2;
}

void MergeSort(int arr[], int l, int r)
{
    if(l == r) return;
    int mid = l + ((r - l) >> 1);
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, r);
    merge(arr, l, r);
}
