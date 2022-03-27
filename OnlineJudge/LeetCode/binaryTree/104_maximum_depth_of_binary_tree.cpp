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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        TreeNode* now = root;
        int curWidth = 1;
        int nextWidth = 0;
        int level = 0;
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);

        while(curWidth -- > 0)
        {
            now = levelQueue.front();
            levelQueue.pop();
            
            if(now->left != NULL)
            {
                levelQueue.push(now->left);
                nextWidth++;
            }
            if(now->right != NULL)
            {
                levelQueue.push(now->right);
                nextWidth++;
            }

            if(curWidth == 0)
            {
                curWidth = nextWidth;
                nextWidth = 0;
                level ++;
            }
        }
        return level;
    }
};

int main()
{
    
    return 0;
}