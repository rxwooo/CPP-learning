#include<bits/stdc++.h>
#include"List.h"
using namespace std;

int main()
{
    List mylist; 
    for(int i = 1; i <= 10; i++)
        ListInsert(mylist, i, i);
    ListInsert(mylist, 5, 15);
    ListTraverse(mylist);
    return 0;
}