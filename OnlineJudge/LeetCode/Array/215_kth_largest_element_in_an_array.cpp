#include <bits/stdc++.h>
using namespace std;

vector<int> heap;
void heapInsert(int pos)
{
    if (pos * 2 + 1 >= heap.size())
        return;
    int lchild = heap[pos * 2 + 1];
    if (pos * 2 + 2 >= heap.size())
    {
        if (heap[pos] > lchild)
        {
            heap[pos * 2 + 1] = heap[pos];
            heap[pos] = lchild;
        }
        return;
    }
    int rchild = heap[pos * 2 + 2];
    if (rchild < lchild)
    {
        if(heap[pos] < rchild)
            return;
        heap[pos * 2 + 2] = heap[pos];
        heap[pos] = rchild;
        heapInsert(pos * 2 + 2);
    }
    else
    {
        if(heap[pos] < lchild)
            return;
        heap[pos * 2 + 1] = heap[pos];
        heap[pos] = lchild;
        heapInsert(pos * 2 + 1);
    }
}
int findKthLargest(vector<int> &nums, int k)
{
    heap = vector<int>(k, 0xc0c0c0c0);
    for (int i = 0; i < nums.size(); i++)
        if(nums[i]>heap[0])
        {
            heap[0] = nums[i];
            heapInsert(0);
        }
    return heap[0];
}

int main()
{
    vector<int> test = {3,2,3,1,2,4,5,5,6};
    findKthLargest(test, 4);
    return 0;
}