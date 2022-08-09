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
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        bool ist = 0;
        Node* cur = head;
        while(cur != NULL)
        {
            Node* tp = new Node(cur->val);
            tp->next = cur->next;
            tp->random = cur->random;
            cur->next = tp;
            cur = tp->next;
        }
        cur = head;
        while(cur != NULL)
        {
            if(ist)
                if(cur->random)
                    cur->random = cur->random->next;
            cur = cur->next;
            ist = !ist;
        }
        Node* root = new Node(-1);
        cur = root;
        Node* head2 = head->next;
        while(1)
        {
            cur->next = head2;
            head->next = head2->next;
            head  = head -> next;
            if(head == NULL)
                break;
            head2 = head2 -> next -> next;
            cur = cur->next;
        }
        return root->next;
    }
};

int main()
{
    
    return 0;
}