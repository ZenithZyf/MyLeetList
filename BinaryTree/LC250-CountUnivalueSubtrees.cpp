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
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        isUnival(root, -1, res);
        return res;
    }
private:
    bool isUnival(TreeNode* root, int val, int& res) {
        if (!root) return true;
        if (!isUnival(root->left, root->val, res) | !isUnival(root->right, root->val, res)) {
            return false;
        }
        res++;
        return root->val == val;
    }
};
