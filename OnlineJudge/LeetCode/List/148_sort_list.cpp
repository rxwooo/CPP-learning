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

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
    ListNode* findMid(ListNode* head)
    {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* root = new ListNode;
        ListNode* cur = root;
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2 -> val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        if(list1 == NULL)
            cur->next = list2;
        else
            cur->next = list1;
        return root->next;
    }

    ListNode* mergeSort(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* mid = findMid(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;
        ListNode* l1 = mergeSort(head);
        ListNode* l2 = mergeSort(head2);
        return merge(l1, l2);
    }
};

int main()
{
    
    return 0;
}