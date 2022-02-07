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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        ans_ = 0;
        maxDepth(root);
        return ans_;
    }
private:
    int ans_;
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int maxDiameter = left + right;
        ans_ = max(ans_, maxDiameter);
        
        return 1 + max(left, right);
    }
};
