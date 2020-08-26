/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        buildGraph(nullptr, root);
        vector<int> ans;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        
        visited.insert(target);
        q.push(target);
        int k = 0;
        while (!q.empty()) {
            int n = q.size();
            if (k++ == K) {
                for (int i = 0; i < n; ++i) {
                    TreeNode* node = q.front(); q.pop();
                    ans.push_back(node->val);
                }
                break;
            }
            
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front(); q.pop();
                visited.insert(node);
                for (auto c : g_[node])
                    if (!visited.count(c))
                        q.push(c);
            }
        }
        return ans;
        
    }
private:
    unordered_map<TreeNode*, vector<TreeNode*>> g_;
    
    void buildGraph(TreeNode* parent, TreeNode* child) {
        if (parent) {
            g_[parent].push_back(child);
            g_[child].push_back(parent);
        }
        if (child->left) buildGraph(child, child->left);
        if (child->right) buildGraph(child, child->right);
    }
};
