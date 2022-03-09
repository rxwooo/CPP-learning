#include <bits/stdc++.h>
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

void heapInsert(int arr[], int index)
{
    // big root
    while ((arr[index] > arr[(index - 1) / 2]) && index != 0)
    {
        arrSwap(arr, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void heapify(int arr[], int index, int heapsize)
{
    // big root

    if(index >=  heapsize / 2)
        return ;

    int lchild = index * 2 + 1;
    int rchild = index;
    if(index * 2 + 2 < heapsize)
        rchild = index * 2 + 2;

    if(arr[lchild] == max(arr[lchild], arr[rchild]))
    {
        arrSwap(arr, index, lchild);
        heapify(arr, lchild, heapsize);
        return ;
    }
    if(index == rchild)
        return ;
    arrSwap(arr, index, rchild);
    heapify(arr, rchild, heapsize);

    return;
}

int main()
{
    int arr[] = {4, 5, 3, 6, 2, 5, 1};
    int len = length(arr);
    int* heap = new int[len];
    int heapsize = 0;

    for(int i = 0; i < len; i++)
    {
        heap[i] = arr[i];
        heapInsert(heap, i);
        heapsize ++;
    }

    while(heapsize > 0)
    {
        arrSwap(heap, 0, heapsize - 1);
        heapsize --;
        heapify(heap, 0, heapsize);
    }

    for(int i = 0; i < len; i++)
        cout << heap[i] << endl;
            
    return 0;
}