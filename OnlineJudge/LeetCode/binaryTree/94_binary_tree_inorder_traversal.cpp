#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traverse;
        if(root == NULL)
            return traverse;
        stack<TreeNode*> nodeStack;
        TreeNode* now = root;
        while(now != NULL || !nodeStack.empty())
        {
            if(now == NULL)
            {
                now = nodeStack.top();
                nodeStack.pop();
                traverse.push_back(now->val);
                now = now->right;
            }   
            else
            {
                nodeStack.push(now);
                now = now->left;
            }
        }
        return traverse;
    }
};

int main()
{
    
    return 0;
}