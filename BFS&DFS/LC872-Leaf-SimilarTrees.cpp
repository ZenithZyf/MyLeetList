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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        vector<int> leaf1;
        vector<int> leaf2;
        findLeaf(root1, leaf1);
        findLeaf(root2, leaf2);
        return leaf1 == leaf2;
    }
private:
    void findLeaf(TreeNode* root, vector<int>& leaf) {
        int flag = 1;
        if (root->left) {
            findLeaf(root->left, leaf);
            flag = 0;
        }
        if (root->right) {
            findLeaf(root->right, leaf);
            flag = 0;
        }
        if (flag == 1) {
            leaf.push_back(root->val);
        }
    }
};
