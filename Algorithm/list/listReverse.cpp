#include<bits/stdc++.h>
#include"list.h"
using namespace std;

Node* listReverse(Node* head)
{
    //Easy edition with a stack
    stack<Node*> nodeStack;
    while(head != NULL)
    {
        nodeStack.push(head);
        head = head->next;
    }
    head = nodeStack.top();
    nodeStack.pop();
    Node* now = head;
    while (nodeStack.size())
    {
        now->next = nodeStack.top();
        nodeStack.pop();
        now = now->next;
    }
    now->next = NULL;
    return head;
}

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


int main()
{
    Node* head = generateOrderedList(0, 5);
    head->showList();
    head = listReverse2(head);
    head->showList();
    return 0;
}