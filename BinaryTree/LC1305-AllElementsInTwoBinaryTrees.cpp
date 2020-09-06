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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> s1, s2;
        
        while ((!s1.empty() || root1 != nullptr) && (!s2.empty() || root2 != nullptr)) {
            if (root1 != nullptr || root2 != nullptr) {
                if (root1 != nullptr) {
                    s1.push(root1);
                    root1 = root1 -> left;
                }
                if (root2 != nullptr) {
                    s2.push(root2);
                    root2 = root2 -> left;
                }
            } else {
                TreeNode* n1 = s1.top();
                TreeNode* n2 = s2.top();
                if (n1 -> val < n2 -> val) {
                    s1.pop();
                    ans.push_back(n1 -> val);
                    root1 = n1 -> right;
                } else {
                    s2.pop();
                    ans.push_back(n2 -> val);
                    root2 = n2 -> right;
                }
            }
        }
        
        while (!s1.empty() || root1 != nullptr) {
            if (root1 != nullptr) {
                s1.push(root1);
                root1 = root1 -> left;
            } else {
                TreeNode* n1 = s1.top(); s1.pop();
                ans.push_back(n1 -> val);
                root1 = n1 -> right;
            }
        }
                
        while (!s2.empty() || root2 != nullptr) {
            if (root2 != nullptr) {
                s2.push(root2);
                root2 = root2 -> left;
            } else {
                TreeNode* n2 = s2.top(); s2.pop();
                ans.push_back(n2 -> val);
                root2 = n2 -> right;
            }
        }
        
        return ans;
        
    }
};
