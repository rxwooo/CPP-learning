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
        ListNode* cur = head->next;
        ListNode* last = head;
        while(cur != NULL)
        {
            if(cur->val == last->val)
            {
                cur = cur->next;
                last->next = cur;
            }
            else
            {
                cur = cur->next;
                last = last->next;
            }
        }
        return head;
    }
};

int main()
{

    return 0;
}