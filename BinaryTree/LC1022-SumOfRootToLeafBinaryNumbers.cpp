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
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
private:
    void dfs(TreeNode* node, int n, int& ans) {
        if (!node) return;
        
        int tmpVal = (n << 1) | (node->val);
        
        if (!node->left && !node->right)
            ans += tmpVal;
        else {
            dfs(node->left, tmpVal, ans);
            dfs(node->right, tmpVal, ans);
        }
    }
};
