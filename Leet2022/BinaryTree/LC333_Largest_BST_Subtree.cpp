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
    int largestBSTSubtree(TreeNode* root) {
        findBST(root);
        return res_;
    }
private:
    int res_ = 0;
    vector<int> findBST(TreeNode* root) {
        if (!root) {
            return {INT_MAX, -INT_MAX, 0};
        }
        vector<int> left = findBST(root->left);
        vector<int> right = findBST(root->right);
        if (left.empty() || right.empty()) {
            return {};
        }
        int leftMin = left[0], leftMax = left[1], leftCount = left[2];
        int rightMin = right[0], rightMax = right[1], rightCount = right[2];
        if (root->val > leftMax && root->val < rightMin) {
            int rootMin = min(leftMin, root->val);
            int rootMax = max(rightMax, root->val);
            int rootCount = leftCount + rightCount + 1;
            res_ = max(res_, rootCount);
            return {rootMin, rootMax, rootCount};
        }
        return {};
    }
};
