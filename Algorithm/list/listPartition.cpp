#include <bits/stdc++.h>
#include "list.h"
using namespace std;

void arrSwap(int arr[], int a, int b)
{
    if (a == b)
        return;
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}

void partition(int *arr, int l, int len, int thres)
{
    int less = l;
    int lar = len;
    int pos = l;
    while (pos < lar && pos < len)
    {
        if (arr[pos] < thres)
        {
            arrSwap(arr, pos, less);
            less++;
        }
        if (arr[pos] > thres)
        {
            lar--;
            arrSwap(arr, pos, lar);
            continue;
        }
        pos++;
    }
}

void listPartition(Node *head, int thres)
{
    int count = 0;
    Node *now = head;
    while (now != NULL)
    {
        count++;
        now = now->next;
    }
    int *arr = new int[count];
    now = head;
    int pos = 0;
    while (now != NULL)
    {
        arr[pos++] = now->num;
        now = now->next;
    }
    partition(arr, 0, count, thres);
    now = head;
    pos = 0;
    while (now != NULL)
    {
        now->num = arr[pos++];
        now = now->next;
    }
    delete arr;
}

Node *listPartition2(Node *head, int thres)
{
    Node *lessHead = NULL, *lessTail = NULL;
    Node *larHead = NULL, *larTail = NULL;
    Node *eqHead = NULL, *eqTail = NULL;
    Node *now = head;
    while (now != NULL)
    {
        if (now->num < thres)
        {
            if (lessHead == NULL)
            {
                lessHead = now;
                lessTail = now;
            }
            else
            {
                lessTail->next = now;
                lessTail = lessTail->next;
            }
        }
        if (now->num > thres)
        {
            if (larHead == NULL)
            {
                larHead = now;
                larTail = now;
            }
            else
            {
                larTail->next = now;
                larTail = larTail->next;
            }
        }
        if (now->num == thres)
        {
            if (eqHead == NULL)
            {
                eqHead = now;
                eqTail = now;
            }
            else
            {
                eqTail->next = now;
                eqTail = eqTail->next;
            }
        }
        now = now->next;
    }
    Node *newHead = NULL, *newTail = NULL;
    if (lessHead != NULL)
    {
        newHead = lessHead;
        newTail = lessTail;
    }
    if (eqHead != NULL)
    {
        if (newHead == NULL)
        {
            newHead = eqHead;
            newTail = eqTail;
        }
        else
        {
            newTail->next = eqHead;
            newTail = eqTail;
        }
    }
    if (larHead != NULL)
    {
        if (newHead == NULL)
        {
            newHead = larHead;
            newTail = larTail;
        }
        else
        {
            newTail->next = larHead;
            newTail = larTail;
        }
    }
    newTail->next = NULL;
    return newHead;
}

int main()
{
    Node *head = generateUnorderedList(0, 9, 5);
    head->showList();
    Node *newHead = listPartition2(head, 5);
    newHead->showList();
    return 0;
}