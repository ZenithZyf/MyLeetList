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
    vector<vector<int>> findLeaves(TreeNode* root) {
        maxDepth(root);
        return res_;
    }
private:
    vector<vector<int>> res_;
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int h = std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
        if (res_.size() < h) {
            res_.push_back({root->val});
        } else {
            res_[h - 1].emplace_back(root->val);
        }
        return h;
    }
};
