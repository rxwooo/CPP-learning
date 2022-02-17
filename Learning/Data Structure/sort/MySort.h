#ifndef __MYSORT__
#define __MYSORT__

#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
typedef int KeyType;

typedef struct RecTpye
{
    KeyType key;
}RecType;

typedef struct Sqlist
{
    RecType r[MAXSIZE];
    int length;
}Sqlist;

Sqlist TestList = {
    {0, 49, 38, 65, 97, 76, 13, 27, 49}, 8
};

bool operator < (RecTpye& r1, RecTpye& r2)
{
    return r1.key<r2.key;
}

bool operator > (RecTpye& r1, RecTpye& r2)
{
    return r1.key>r2.key;
}

bool operator == (RecTpye& r1, RecTpye& r2)
{
    return r1.key == r2.key;
}

ostream& operator << (ostream& os , Sqlist sq)
{
    for(int i = 1; i<=sq.length; i++)
    {
        os << sq.r[i].key<<" ";
    }
    return os;
}


void BInsertSort(Sqlist& l)
{
    for(int i = 2; i<l.length; i++)
    {
        l.r[0] = l.r[i];
        int low = 1;
        int high = i - 1;
        while( low <= high )
        {
            int m = (low + high) / 2;
            if(l.r[0]<l.r[m])
                high = m - 1;
            else
                low  = m + 1;
        }
        for( int j = i - 1; j>=high + 1; j--)
            l.r[j+1] = l.r[j];
        l.r[high + 1] = l.r[0];
    }
}

//dict默认等于1时为插入排序， 可作为希儿排序的子函数
void InsertSort(Sqlist &sq, int disc)
{
    for(int i = disc + 1; i <= sq.length; i++)
    {
        if(sq.r[i] < sq.r[i - disc])
        {
            sq.r[0] = sq.r[i];
            int j;
            for(j = i - disc; j > 0; j -= disc)
            {
                if(sq.r[j]<sq.r[0])
                {
                    break;
                }
                sq.r[j + disc] = sq.r[j];
            }
            sq.r[j+disc] = sq.r[0];
        }
    }
}

//希尔排序，参数分别为待排序结构，希尔增量数组，以及轮次
void ShellSort(Sqlist& sq, int dict[], int t)
{
    for(int i =0; i<t; i++)
    {
        InsertSort(sq, dict[i]);
    }
}

#endif