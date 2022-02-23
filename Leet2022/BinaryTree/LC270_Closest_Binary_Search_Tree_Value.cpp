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
    int closestValue(TreeNode* root, double target) {
        res_ = root->val;
        dfs(root, target);
        return res_;
    }
private:
    int res_ = 0;
    void dfs(TreeNode* root, const double target) {
        if (!root) {
            return;
        }
        if (abs(root->val - target) < abs(res_ - target)) {
            res_ = root->val;
        }
        dfs(root->left, target);
        dfs(root->right, target);
        return;
    }
};
