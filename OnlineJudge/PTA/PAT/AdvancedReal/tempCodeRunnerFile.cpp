#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> init;
    vector<int> preSort;
    for(int i = 0; i < n; i ++)
    {
        int tp;
        cin >> tp;
        init.push_back(tp);
    }
    for(int i = 0; i < n; i++)
    {
        int tp;
        cin >> tp;
        preSort.push_back(tp);
    }
    int flag = 0;
    int pos;
    for(int i = 1; i < n; i++)
    {
        if(preSort[i] < preSort[i - 1])
        {
            if(!flag)
                pos = i;
            if(preSort[i] != init[i])
                break;
            flag = i;
        }
    }
    if(flag == n - 1) //insertion sort
    {
        cout << "Insertion Sort" << endl;
        for(int i = flag; i > 0; i --)
            if(preSort[i] < preSort[i - 1])
                swap(preSort[i], preSort[i - 1]);
            else
                break;
        for(int i = 0; i < n; i++)
        {
            cout << preSort[i];
            if(i != n - 1)
                cout << " ";
        }
    }
    else //heap sort
    {
        cout << "Heap Sort" << endl;
        //heapify
        make_heap(init.begin(), init.end());
        for(int i = 0; i < n; i++)
        {
            pop_heap(init.begin(), init.end()-i);
            if(init[n - i - 1] != preSort[n - i - 1])
                break;
        }
        for(int i = 0; i < n; i++)
        {
            cout << init[i];
            if(i != n - 1)
                cout << " ";
        }
    }
    return 0;
}