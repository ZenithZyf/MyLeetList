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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        map<int, vector<int>> col_map;
        queue<pair<int, TreeNode*>> row_q;
        row_q.push({0, root});
        while (!row_q.empty()) {
            auto r = row_q.front(); row_q.pop();
            col_map[r.first].emplace_back(r.second->val);
            if (r.second->left) {
                row_q.push({r.first - 1, r.second->left});
            }
            if (r.second->right) {
                row_q.push({r.first + 1, r.second->right});
            }
        }
        for (auto col : col_map) {
            res.emplace_back(col.second);
        }
        return res;
    }
};
