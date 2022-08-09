#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return NULL;
        ListNode large;
        ListNode less;
        ListNode* larCur = &large;
        ListNode* lesCur = &less;
        ListNode* cur = head;
        while(cur != NULL)
        {
            if(cur->val < x)
            {
                lesCur->next = cur;
                lesCur = cur;
            }
            else
            {
                larCur->next = cur;
                larCur = cur;
            }
            cur = cur->next;
        }
        lesCur->next = large.next;
        larCur->next = NULL;
        return less.next;
    }
};

int main()
{
    
    return 0;
}