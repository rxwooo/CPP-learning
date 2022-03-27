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
    int len;
    int depth(TreeNode* root){
        if (root == NULL) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        len = max(len, left + right + 1);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        len = 1;
        depth(root);
        return len - 1;
    }
};

int main()
{

    return 0;
}