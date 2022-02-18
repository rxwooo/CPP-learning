#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[]);

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
    InsertionSort(arr);
    for(int i = 0; i < length(arr); i++)
        cout << arr[i] << endl;
}

void InsertionSort(int arr[])
{
    int len = length(arr);
    for(int i = 0; i < len - 1; i++)
        for(int j = i; j > 0; j--)
            if(arr[i+1] < arr[i])
                arr_swap(arr, i, i-1);
            else break;
}