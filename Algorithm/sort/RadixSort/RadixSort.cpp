#include<bits/stdc++.h>
using namespace std;

void arrSwap(int arr[], int a, int b)
{
    if(a == b) return;
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

template <class T>
int length(T &arr)
{
    return sizeof(arr) / sizeof(arr[0]);
}

int maxBit(int arr[], int l, int r)
{
    int big = 0xc0c0c0c0;
    for(int i = l; i <= r; i++)
        if(arr[i] > big)
            big = arr[i];
    
    for(int i = 0; ;i++)
        if(big / pow(10, i) < 1)
            return i;
    return 0;
}

int getDigitNum(int num, int digit)
{
    for(int i = 1; i < digit; i++)
        num /= pow(10, i);
    return num % 10;
}

void RadixSort(int arr[], int l, int r)
{
    int bits = maxBit(arr, l, r);
    int* bucket = new int[r - l + 1];
    int* count = new int[10];

    memset(bucket, 0, sizeof(int) * (r - l + 1));
    memset(count, 0, sizeof(int) * 10);

    for(int i = 1; i <= bits; i++)
    {
        for(int j = l; j <= r; j++)
            count[getDigitNum(arr[j], i)] ++;
        for(int j = 1; j < 10; j++)
            count[j] += count[j - 1];
        for(int j = r; j >= l; j--)
            bucket[ --count[getDigitNum(arr[j], i)]] = arr[j];
        memcpy(arr + l, bucket + l, sizeof(int) * (r - l));
    }
}

int main()
{
    
    int arr[] = {4, 5, 3, 6, 2, 5, 1};
    int len = length(arr);
    RadixSort(arr, 0, len - 1);
    for(int i = 0; i < len; i++)
        cout << arr[i] << endl;
    return 0;
}