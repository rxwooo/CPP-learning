#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* cyclicShiftTree(TreeNode* root, int k) {
        vector<vector<int>> levelCount;
        if(root == NULL)
            return NULL;
        vector<TreeNode*> nodeVec;
        queue<TreeNode*> nodeQue;
        nodeQue.push(root);
        while (nodeQue.size() != 0)
        {
            TreeNode* node = nodeQue.front();
            nodeQue.pop();
            nodeVec.push_back(node);
            if(node != NULL)
            {
                nodeQue.push(node->left);
                nodeQue.push(node->right);   
            }
        }
        levelCount.push_back({0, 1, 1});
        int begin = levelCount.back()[1];
        while (begin < nodeVec.size())
        {
            int dis = levelCount.back()[1] - levelCount.back()[0] * 2;
            int count = 0;
            for(int i = 0; i < dis; i++)
                if(nodeVec[i + levelCount.back()[1]] != NULL)
                    count ++;
            levelCount.push_back({levelCount.back()[1], levelCount.back()[1]+dis, count});
            begin = levelCount.back()[1]+dis;
        }
        levelCount.erase(levelCount.end());
    }

int main()
{
    
    return 0;
}