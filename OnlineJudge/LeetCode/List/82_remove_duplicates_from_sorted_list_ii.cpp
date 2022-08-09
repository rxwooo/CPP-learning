#include <bits/stdc++.h>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode root;
        root.next = head;
        ListNode* last = &root;
        ListNode* cur = head;
        while(cur != NULL)
        {
            ListNode* tp = cur->next;
            while(tp != NULL && tp->val == cur->val)
                tp = tp->next;
            if(tp != cur->next)
                last -> next = tp;
            else
                last = last->next;
            cur = tp;
        }
        return root.next;
    }
};

int main()
{

    return 0;
}