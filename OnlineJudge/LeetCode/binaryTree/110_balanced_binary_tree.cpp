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
    int _isBalanced(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = _isBalanced(root->left);
        int right = _isBalanced(root->right);

        if(left == -1 || right == -1) return -1;
        
        if(abs(right - left) < 2)
            return max(left, right) + 1;
        return -1;
    }

    bool isBalanced(TreeNode* root) {
        return _isBalanced(root) != -1;
    }
};

int main()
{
    
    return 0;
}