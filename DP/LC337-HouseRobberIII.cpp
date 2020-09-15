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
    int rob(TreeNode* root) {
        pair<int, int> res = dp(root);
        return std::max(res.first, res.second);
    }
private:
    pair<int, int> dp(TreeNode* root) {
        if (!root) return make_pair (0, 0);
        
        //pair.first: not rob root maximum profit;
        //pair.second: rob root maximum profit;
        pair<int, int> left = dp(root->left);
        pair<int, int> right = dp(root->right);
        
        int not_do = std::max(left.first, left.second)
               + std::max(right.first, right.second);
        
        int do_it = root->val + left.first + right.first;
        
        return make_pair (not_do, do_it);
    }
};
