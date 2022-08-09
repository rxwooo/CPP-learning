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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next == NULL)
            return head;
        ListNode root;
        root.next = head;
        ListNode* edge = &root;
        ListNode* cur = head;
        while(cur && (right --, --left))
        {
            edge = cur;
            cur = cur->next;
        }
        while(cur && right --)
        {
            ListNode* tp = cur->next;
            cur->next = tp->next;
            tp->next = edge->next;
            edge->next = tp;
        }
        return root.next;
    }
};

int main()
{
    
    return 0;
}