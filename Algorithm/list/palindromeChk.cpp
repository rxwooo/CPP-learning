#include<bits/stdc++.h>
#include"list.h"
using namespace std;

Node* listReverse2(Node* head)
{
    //Complex edition with some variables
    if(head->next == NULL)
        return head;
    Node* now = head->next;
    Node* last = head;
    last->next = NULL;
    while (now->next != NULL)
    {
        Node* tp = now;
        now = now->next;
        tp->next = last;
        last = tp;
    }
    now->next = last;
    return now;
}

Node* generatePalindromeList(int bg, int ed, int mode)
{
    Node* head = generateOrderedList(bg, ed);
    Node* head2 = generateOrderedList(bg, ed);
    Node* reverse = listReverse2(head2);

    Node* tp = head;
    while (tp->next != NULL)
    {
        tp = tp->next;
    }
    if(!mode)
        tp->next = reverse;
    else
        tp->next = reverse->next;
    
    return head;
}

bool palindromeChk(Node* head)
{
    stack<Node*> nodeStack;
    Node* now = head;
    while(now != NULL)
    {
        nodeStack.push(now);
        now = now->next;
    }
    now = head;
    while(now != NULL)
    {
        Node* tp = nodeStack.top();
        if(tp->num != now->num)
            return 0;
        nodeStack.pop();
        now = now->next;
    }
    return 1;
}

bool palindromeChk2(Node* head)
{
    if(head->next == NULL)
        return 1;

    Node* fast = head;
    Node* slow = head;
    bool odd = 0;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next; 
    }
    odd = fast == NULL? 0: 1;

    Node* center = slow;
    Node* now = slow->next;
    Node* last = slow;
    while (now != NULL)
    {
        Node* tp = now->next;
        now->next = last;
        last = now;
        now = tp;
    }

    now = head;
    Node* nowReverse = last;
    while(now != center)
    {
        if(now->num != nowReverse->num)
            return 0;
        now = now->next;
        nowReverse = nowReverse->next;
    }
    return 1;
}

bool palindromeChk3(Node* head)
{
    if(head == NULL)
        return 0;
    if(head->next == NULL)
        return 1;

    Node* fast = head;
    Node* slow = head;
    bool odd = 0;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    odd = fast == NULL? 0: 1;

    Node* center = slow;
    stack<Node*> nodeStack;
    while(slow != NULL)
    {
        nodeStack.push(slow);
        slow = slow->next;
    }
    
    Node* now = head;
    while(now != center)
    {
        Node* tp = nodeStack.top();
        nodeStack.pop();
        if(now->num != tp->num)
            return 0;
        now = now->next;
    }
    return 1; 
}

int main()
{
    Node* head = generatePalindromeList(0, 5, 1);
    cout << palindromeChk3(head) << endl;

    return 0;
}