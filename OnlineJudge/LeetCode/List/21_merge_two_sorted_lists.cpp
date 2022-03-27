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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* head = new ListNode();
        ListNode* root = head;
        while( cur1 != NULL && cur2 != NULL)
        {
            if(cur1 -> val <= cur2 -> val)
            {
                head->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                head->next = cur2;
                cur2 = cur2->next;
            }
            head = head -> next;
        }
        if(cur1 != NULL)
            head->next = cur1;
        else
            head->next = cur2;
        return root->next;
    }
};

int main()
{

    return 0;
}