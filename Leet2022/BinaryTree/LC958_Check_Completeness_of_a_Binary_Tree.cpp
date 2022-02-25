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
    bool isCompleteTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        queue<TreeNode*> q_node;
        q_node.push(root);
        while (q_node.front() != nullptr) {
            TreeNode* cur = q_node.front(); q_node.pop();
            q_node.push(cur->left);
            q_node.push(cur->right);
        }
        while (!q_node.empty() && q_node.front() == nullptr) {
            q_node.pop();
        }
        return q_node.empty();
    }
};
