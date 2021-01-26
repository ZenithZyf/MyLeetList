class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> in(n);
        for (int i : leftChild) {
            if (i >= 0) { in[i]++; }
        }
        for (int i : rightChild) {
            if (i >= 0) { in[i]++; }
        }
        
        int root = 0;
        for (int k = 0; k < n; k++) {
            if (in[k] > 1) { return false; }
            if (in[k] == 0) { 
                if (root == 0) { root = k; }
                else { return false; }
            }
        }
        
        vector<int> visited(n);
        queue<int> q;
        q.push(root);
        visited[root]++;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            
            if (leftChild[cur] != -1) {
                if (visited[leftChild[cur]] > 1) { return false; }
                visited[leftChild[cur]]++;
                q.push(leftChild[cur]);
            }
            
            if (rightChild[cur] != -1) {
                if (visited[rightChild[cur]] > 1) { return false; }
                visited[rightChild[cur]]++;
                q.push(rightChild[cur]);
            }
        }
        
        return accumulate(visited.begin(), visited.end(), 0) == n;
    }
};
