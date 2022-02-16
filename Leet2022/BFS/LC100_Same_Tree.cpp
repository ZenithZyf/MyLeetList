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
    bool isSameTree(TreeNode* p, TreeNode* q) {    
        queue<TreeNode*> cur_nodes;
        cur_nodes.push(p);
        cur_nodes.push(q);
        
        while (!cur_nodes.empty()) {
            TreeNode* p_cur = cur_nodes.front(); cur_nodes.pop();
            TreeNode* q_cur = cur_nodes.front(); cur_nodes.pop();
            
            if (!p_cur && !q_cur) {
                continue;
            } else if (!p_cur || !q_cur) {
                return false;
            } else {
                if (p_cur->val == q_cur->val) {
                    cur_nodes.push(p_cur->left);
                    cur_nodes.push(q_cur->left);
                    cur_nodes.push(p_cur->right);
                    cur_nodes.push(q_cur->right);
                } else {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};
