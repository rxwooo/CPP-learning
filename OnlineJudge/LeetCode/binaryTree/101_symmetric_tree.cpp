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
    bool check(TreeNode* Lroot,TreeNode* Rroot)
    {
        if((Lroot == NULL && Rroot != NULL) || (Lroot != NULL && Rroot == NULL)) 
            return 0;

        if(Lroot == NULL && Rroot == NULL)
            return 1;

        if(Lroot->val != Rroot->val)
            return 0;

        bool chk1 = check(Lroot->left, Rroot->right);
        bool chk2 = check(Lroot->right, Rroot->left);
        return chk1 * chk2;
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode* Lroot = root->left;
        TreeNode* Rroot = root->right;

        return check(Lroot, Rroot);
    }
};

int main()
{
    
    return 0;
}