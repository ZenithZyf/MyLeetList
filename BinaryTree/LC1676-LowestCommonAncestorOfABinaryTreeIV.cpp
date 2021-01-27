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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if (nodes.size() == 1) { return nodes[0]; }
        TreeNode* ans = dfs(root, nodes);
        return ans;
    }
private:
    TreeNode* dfs(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) { return NULL; }
        if (count(nodes.begin(), nodes.end(), root)) { return root; }
        
        TreeNode* left = dfs(root->left, nodes);
        TreeNode* right = dfs(root->right, nodes);
        if (left != NULL && right != NULL) { return root; }
        return left == NULL ? right : left;
    }
};
