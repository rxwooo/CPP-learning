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
    TreeNode* myflatten(TreeNode* root)
    {
        TreeNode *right, *left;
        left = root->left;
        right = root->right;
        if(left == NULL && right == NULL)
            return root;
        if(left == NULL) {}
        if(right == NULL)
        {
            root->right = left;
            root->left = NULL;
        }
        else
        {
            TreeNode* leftLast = myflatten(left); 
            leftLast->right = right;
        }
        return myflatten(right);
    }

    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        myflatten(root);
    }
};

int main()
{
    
    return 0;
}