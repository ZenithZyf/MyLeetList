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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        inOrder(root, target, k, res);
        return res;
    }
private:
    void inOrder(TreeNode* root, const double target, const int k, vector<int>& res) {
        if (!root) {
            return;
        }
        inOrder(root->left, target, k, res);
        if (res.size() < k) {
            res.emplace_back(root->val);
        } else if (abs(root->val - target) < abs(res[0] - target)) {
            res.erase(res.begin());
            res.emplace_back(root->val);
        } else {
            return;
        }
        inOrder(root->right, target, k, res);
        return;
    }
};
