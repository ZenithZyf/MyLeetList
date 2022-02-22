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
    int rob(TreeNode* root) {
        vector<int> res = dp(root);
        return max(res[0], res[1]);
    }
private:
    vector<int> dp(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);
        int do_it = root->val + left[0] + right[0];
        int not_do_it = max(left[0], left[1]) + max(right[0], right[1]);
        return {not_do_it, do_it};
    }
};
