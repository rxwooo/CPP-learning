#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *solve(vector<ListNode *> &a)
{
    unordered_map<long long, ListNode*> nodeMap;
    int len = a.size(); 
    for(int i = 0; i < len; i++)
    {
        ListNode* tp = a[i];
        while(tp != NULL) 
        {
            if(nodeMap.find(tp->val) != nodeMap.end())
                nodeMap.insert({tp->val, tp});
            tp = tp->next;
        }
    }
    int flag = 0;
    for(int i = 1; i < 200010; i++)
        if(nodeMap.find(i) != nodeMap.end())
        {
            flag = i;
            break;
        }
    return nodeMap[flag];
}

int main()
{

    return 0;
}