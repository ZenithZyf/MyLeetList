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
    int equalToDescendants(TreeNode* root) {
        int cnt = 0;
        sumDescendants(root, cnt);
        return cnt;
    }
private:
    long sumDescendants(TreeNode* root, int& cnt) {
        if (!root) {
            return 0;
        }
        long left = sumDescendants(root->left, cnt);
        long right = sumDescendants(root->right, cnt);
        if (root->val == left + right) {
            ++cnt;
        }
        return root->val + left + right;
    }
};
