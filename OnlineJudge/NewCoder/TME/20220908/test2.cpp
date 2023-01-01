#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int getTreeSum(TreeNode* tree) {
        // int left = dfs(tree->left);
        // int right = dfs(tree->right);
        // return (max(right, left) * 2 + 1) % 1000000007;
        if(tree == NULL)
            return 0;
        
        int left = getTreeSum(tree->left);
        int right = getTreeSum(tree->right);
        if(left == 0 && right == 0)
        {
            return 1;
        }
        //res += (max(right, left) * 2 + 2) % 1000000007;
        return (max(right, left) * 2 + 1) % 1000000007;
    }
};

int main()
{
    
    return 0;
}