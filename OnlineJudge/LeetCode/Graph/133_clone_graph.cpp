#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> _map;
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        if(_map.find(node) != _map.end())
            return _map[node];
        Node* newNode = new Node(node->val);
        _map.insert({node, newNode});
        int len = node->neighbors.size();
        for(int i = 0; i < len; i++)
        {
            Node* tp = cloneGraph(node->neighbors[i]);
            newNode->neighbors.push_back(tp);
        }
        return newNode;
    }
};

int main()
{
    
    return 0;
}