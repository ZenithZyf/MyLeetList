/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        count_ = 0;
        TreeNode* res = dfs(root, p, q);
        return count_ == 2 ? res : NULL;
    }
private:
    int count_;
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) { return NULL; }
        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);
        if (root == p || root == q) {
            count_++;
            return root;
        }
        if (left != NULL && right != NULL) {
            return root;
        }
        return left == NULL ? right : left;
    }
};
