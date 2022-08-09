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
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return 1;
        
        int lastNum;
        bool first = 1;
        stack<TreeNode*> call;
        call.push(root);
        while(call.size())
        {
            TreeNode* cur = call.top();
            call.pop();
            if(cur)
            {
                if(cur->left) call.push(cur->left);
                call.push(cur);
                call.push(NULL);
                if(cur->right) call.push(cur->right);
            }
            else
            {
                int curNum = call.top()->val;
                call.pop();
                if(first)
                {
                    lastNum = curNum;
                    first = 0;
                }
                else
                {
                    if(curNum >= lastNum) return 0;
                    lastNum = curNum;
                }
            }
        }
        return 1;
    }
};

int main()
{

    return 0;
}