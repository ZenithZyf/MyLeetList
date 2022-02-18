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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> right_view;
        queue<TreeNode*> q_nodes;
        q_nodes.push(root);
        while (!q_nodes.empty()) {
            int sz = q_nodes.size();
            for (int i = 0; i < sz - 1; ++i) {
                TreeNode* cur_node = q_nodes.front(); q_nodes.pop();
                if (cur_node->left) {
                    q_nodes.push(cur_node->left);
                }
                if (cur_node->right) {
                    q_nodes.push(cur_node->right);
                }
            }
            TreeNode* right_node = q_nodes.front(); q_nodes.pop();
            right_view.emplace_back(right_node->val);
            if (right_node->left) {
                q_nodes.push(right_node->left);
            }
            if (right_node->right) {
                q_nodes.push(right_node->right);
            }
        }
        return right_view;
    }
};
