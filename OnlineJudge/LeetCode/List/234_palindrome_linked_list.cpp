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

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* last = NULL;
        ListNode* sNext;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;

            sNext = slow->next;
            slow->next = last;
            last = slow;
            slow = sNext;
        }
        
        if(!(fast == NULL))
            slow = slow->next;

        while(slow != NULL)
        {
            if(slow->val != last->val)
                return 0;
            slow = slow->next;
            last = last->next;
        }
        return 1;
    }
};

int main()
{

    return 0;
}