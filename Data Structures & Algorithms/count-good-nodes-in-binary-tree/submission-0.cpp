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
    void helper(TreeNode* root, int &ans, int maxi) {

        if (!root) return;

        if (root->val >= maxi) {
            ans++;
            maxi = root->val;
        }

        helper(root->left, ans, maxi);
        helper(root->right, ans, maxi);
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        helper(root, ans, root->val);
        return ans;
    }
};
