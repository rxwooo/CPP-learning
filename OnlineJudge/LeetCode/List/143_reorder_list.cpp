#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        //find mid
        if(head == NULL)
            return ;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        //reverse the last half list
        ListNode* last = NULL;
        ListNode* cur = slow->next;
        slow -> next = NULL;
        while(cur != NULL)
        {
            ListNode* tp = cur -> next;
            cur->next = last;
            last = cur;
            cur = tp;
        }

        //merge two list
        ListNode* root = new ListNode;
        cur = root;
        bool odd = 1;
        while(head != NULL && last != NULL)
        {
            if(odd)
            {
                cur->next = head;
                head = head->next;
            }
            else
            {
                cur->next = last;
                last = last ->next;
            }
            odd = !odd;
            cur = cur->next;
        }
        if(head)
            cur->next = head;
        else
            cur->next = last;
    }
};

int main()
{
    
    return 0;
}