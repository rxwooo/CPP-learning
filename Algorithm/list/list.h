#ifndef __MYLIST__
#define __MYLIST__

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node() {}
    Node(int num) : num(num) {}
    int num;
    Node *next;
    void showList()
    {
        Node *head = this;
        while (head != NULL)
        {
            cout << head->num << endl;
            head = head->next;
        }
    }
};

extern Node* listReverse2(Node* head);

Node *generateOrderedList(int bg, int ed)
{
    if (ed - bg < 1)
        return NULL;
    Node *head = new Node(bg);
    head->next = NULL;
    Node *now = head;
    for (int i = bg + 1; i < ed; i++)
    {
        Node *tp = new Node(i);
        now->next = tp;
        now = now->next;
        now->next = NULL;
    }
    return head;
}

Node *generateUnorderedList(int bg, int ed, int len)
{
    srand(time(NULL));
    if (ed < bg)
    {
        bg = bg ^ ed;
        ed = bg ^ ed;
        bg = bg ^ ed;
    }
    int random = bg == ed ? bg : rand() % (ed - bg) + bg;
    Node *head = new Node(random);
    head->next = NULL;
    Node *now = head;
    for(int i = 1; i < len; i++)
    {
        Node *tp = new Node();
        tp->num = bg == ed ? bg : rand() % (ed - bg) + bg;
        now->next = tp;
        now = now->next;
        now->next = NULL;
    }
    return head;
}

void destroyList(Node *node)
{
    while (node->next != NULL)
    {
        Node *tp = node;
        node = node->next;
        delete tp;
    }
}

#endif