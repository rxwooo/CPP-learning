#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* now = head;
        ListNode* last = NULL;
        ListNode* nx;
        while (now != NULL)
        {
            nx = now->next;
            now->next = last;
            last = now;
            now = nx;
        }
        return last; 
    }
};

int main()
{
    
    return 0;
}