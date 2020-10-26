/**
 * @ Author: tekky
 * @ Create Time: 2020-10-26 11:31:48
 * @ Modified by: tekky
 * @ Modified time: 2020-10-26 11:32:08
 */

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
    vector<int> ans;
    void handler(TreeNode * root) {
        if (root != nullptr) {
            ans.push_back(root->val);
            handler(root->left);
            handler(root->right);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        handler(root);
        return ans;
    }
};