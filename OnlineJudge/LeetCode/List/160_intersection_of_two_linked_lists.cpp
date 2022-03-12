#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len1 = 0;
        int len2 = 0;
        ListNode* now1 = headA;
        ListNode* now2 = headB;
        while(now1->next != NULL)
        {
            now1 = now1->next;
            len1 ++;
        }
        while(now2->next != NULL)
        {
            now2 = now2->next;
            len2 ++;
        }
        if(now1 != now2)
            return NULL;
        now1 = headA;
        now2 = headB;
        if(len1 > len2)
            while (len1-- > len2)
                now1 = now1->next;
        else if(len1 < len2)
            while (len2-- > len1)
                now2 = now2->next;
        while(now1 != NULL) 
        {
            if(now1 == now2)
                return now1;
            now2 = now2->next;
            now1 = now1->next;
        }
        return now1;
    }

};

int main()
{

    return 0;
}