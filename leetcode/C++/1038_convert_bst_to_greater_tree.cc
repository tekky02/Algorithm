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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> nodes;
        TreeNode* head = root;
        int sum = 0;
        while (!nodes.empty() || root) {
            while (root) {
                nodes.push(root);
                root = root->right;
            }
            root = nodes.top();
            nodes.pop();
            root->val += sum;
            sum = root->val;
            root = root->left;
        }
        return head;
    }
};