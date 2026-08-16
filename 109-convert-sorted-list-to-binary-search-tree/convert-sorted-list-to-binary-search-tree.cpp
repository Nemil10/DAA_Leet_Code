class Solution {
public:
    TreeNode* build(vector<int>& a, int l, int r)
    {
        if(l > r)
            return NULL;

        int mid = (l + r) / 2;

        TreeNode* root = new TreeNode(a[mid]);

        root->left = build(a, l, mid - 1);
        root->right = build(a, mid + 1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int> a;

        while(head != NULL)
        {
            a.push_back(head->val);
            head = head->next;
        }

        return build(a, 0, a.size() - 1);
    }
};