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
    int longestConsecutive(TreeNode* root) {
        dfs(root, 1, -INT_MAX);
        return maxlen_;
    }
private:
    int maxlen_ = 0;
    void dfs(TreeNode* root, int len, int parentValue) {
        if (!root) {
            return;
        }
        if (parentValue + 1 == root->val) {
            ++len;
        } else {
            len = 1;
        }
        maxlen_ = max(maxlen_, len);
        dfs(root->left, len, root->val);
        dfs(root->right, len, root->val);
        return;
    }
};
