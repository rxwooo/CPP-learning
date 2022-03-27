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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;

        TreeNode* now = root;
        int maxWidth = 1;
        int curWidth = 1;
        int nextWidth = 0;
        int level = 0;
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);

        while(curWidth -- > 0)
        {
            if(nextWidth == 0)
            {
                vector<int> tp;
                result.push_back(tp);
            }
            now = levelQueue.front();
            levelQueue.pop();
            result[level].push_back(now->val);
            
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
                if(maxWidth < nextWidth)
                    maxWidth = nextWidth;
                curWidth = nextWidth;
                nextWidth = 0;
                level ++;
            }
        }
        return result;
    }
};

int main()
{
    
    return 0;
}