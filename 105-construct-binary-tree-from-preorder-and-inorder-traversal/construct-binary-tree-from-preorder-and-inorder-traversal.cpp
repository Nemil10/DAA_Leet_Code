/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie)
    {
        if(ps > pe || is > ie)
            return NULL;

        int rootValue = preorder[ps];
        TreeNode* root = new TreeNode(rootValue);

        int pos = is;

        while(inorder[pos] != rootValue)
            pos++;

        int leftSize = pos - is;

        root->left = solve(preorder, inorder, ps + 1, ps + leftSize, is, pos - 1);

        root->right = solve(preorder, inorder, ps + leftSize + 1, pe, pos + 1, ie);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};