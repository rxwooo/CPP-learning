#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root)
    {
        if(root == NULL)
            return true;
        vector<long long> valVec;
        stack<TreeNode*> nodeStack;
        TreeNode* cur = root;
        while(cur != NULL || !nodeStack.empty())
        {
            if(cur != NULL)
            {
                nodeStack.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = nodeStack.top();
                nodeStack.pop();
                valVec.push_back(cur->val);
                cur = cur->right;
            }
        }
        for(int i = 1; i < valVec.size(); i++)
            if(valVec[i] <= valVec[i - 1])
                return false;
        return true;
    }
};

int main()
{

    return 0;
}