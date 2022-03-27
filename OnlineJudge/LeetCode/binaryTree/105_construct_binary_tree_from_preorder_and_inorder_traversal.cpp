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
    int prePos = 0;
    int getPos(vector<int>& inorder, int l, int r, int target)
    {
        for(int i = l; i < r; i++)
            if(inorder[i] == target)
                return i;
        return -1;
    }

    TreeNode* getChild(vector<int>& inorder, vector<int>& preorder, int l, int r)
    {
        int pos = -1;
        int val;
        TreeNode* node;

        if(l == r)
            return NULL;
        if(r - l == 1)
        {
            node = new TreeNode(inorder[l]);
            prePos ++;
            return node;
        }        
        
        for(int i = l; i < r; i++)
            if(inorder[i] == preorder[prePos])
                pos = i;

        if(pos != -1)
        {
            node = new TreeNode(inorder[pos]);
            prePos ++;
        }
        else
        {
            return NULL;
        }
        
        TreeNode *left, *right;
        left = getChild(inorder, preorder, l, pos);
        right = getChild(inorder, preorder, pos + 1, r);
        node->left = left;
        node->right = right;
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        
        return getChild(inorder, preorder, 0, len);
    }
};

int main()
{
    
    return 0;
}