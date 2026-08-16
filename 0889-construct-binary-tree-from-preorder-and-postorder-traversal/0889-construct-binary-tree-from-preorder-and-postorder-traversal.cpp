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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int &i, int l, int r)
    {
        if(l > r)
            return NULL;

        TreeNode* root = new TreeNode(preorder[i]);
        i++;

        if(l == r)
            return root;

        int j = l;

        while(postorder[j] != preorder[i])
            j++;

        root->left = solve(preorder, postorder, i, l, j);
        root->right = solve(preorder, postorder, i, j + 1, r - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int i = 0;
        return solve(preorder, postorder, i, 0, postorder.size() - 1);
    }
};