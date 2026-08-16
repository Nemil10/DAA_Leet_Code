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

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int is, int ie, int ps, int pe)
    {
        if(is > ie || ps > pe)
            return NULL;

        int rootValue = postorder[pe];

        TreeNode* root = new TreeNode(rootValue);

        int pos = is;

        while(inorder[pos] != rootValue)
            pos++;

        int leftSize = pos - is;

        root->left = solve(inorder, postorder,
                           is, pos - 1,
                           ps, ps + leftSize - 1);

        root->right = solve(inorder, postorder,
                            pos + 1, ie,
                            ps + leftSize, pe - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        return solve(inorder, postorder,
                     0, inorder.size() - 1,
                     0, postorder.size() - 1);
    }
};