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
    
    int helper(TreeNode * root, int curmax, int curmin) {
        if (root == nullptr) return curmax - curmin;
        curmax = max(root->val, curmax);
        curmin = min(root->val, curmin);
        int l = helper(root->left, curmax, curmin);
        int r = helper(root->right, curmax, curmin);
        return max(l, r);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;
        return helper(root, root->val, root->val);
    }
};

