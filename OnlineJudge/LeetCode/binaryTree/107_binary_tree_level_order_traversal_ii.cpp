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
    vector<vector<int>> tra;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        levelTra(root, 0);
        reverse(tra.begin(), tra.end());
        return tra;
    }

    void levelTra(TreeNode* root, int level)
    {
        if(root == NULL)
            return ;
        if(tra.size() < level + 1)
            tra.push_back({});
        
        levelTra(root->left, level + 1);
        levelTra(root->right, level + 1);

        tra[level].push_back(root->val);
    }
};

int main()
{
    
    return 0;
}